/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:02:32 by etien             #+#    #+#             */
/*   Updated: 2025/04/24 12:56:53 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// This function checks that the string is only composed of digits.
bool hasOnlyDigits(const std::string &input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		char c = input[i];
		if (!isdigit(c))
			return false;
	}
	return true;
}

// enforce YYYY-MM-DD format (in index form: 0123-56-89)
// A map will store unique keys. If we don't enforce a strict format, both
// 2009-09-09 and 2009-9-9 could potentially be stored, leading to conflict.
bool validateDate(const std::string &date)
{
	// checking that date format only uses hyphens as separators
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	std::string year = date.substr(0, 4); // YYYY
	std::string month = date.substr(5, 2); // MM
	std::string day = date.substr(8, 2); // DD

	// checking that date components only contain digits
	if (!hasOnlyDigits(year) || !hasOnlyDigits(month) || !hasOnlyDigits(day))
		return false;

	// atoi will ignore leading zeros so "01" will be converted to '1'
	int yearInt = std::atoi(year.c_str());
	int monthInt = std::atoi(month.c_str());
	int dayInt = std::atoi(day.c_str());

	// checking month range
	if (monthInt < 1 || monthInt > 12)
		return false;

	// months with 31 days
	if (monthInt == 1 || monthInt == 3 || monthInt == 5 || monthInt == 7 || monthInt == 8 || monthInt == 10 || monthInt == 12)
		if (dayInt < 1 || dayInt > 31)
			return false;

	// months with 30 days
	if (monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11)
		if (dayInt < 1 || dayInt > 30)
			return false;

	// February
	if (monthInt == 2)
	{
		if (dayInt < 1 || dayInt > 29)
			return false;
		// leap years are divisible by 4 and Februrary only has 28 days in non-leap years
		if (yearInt % 4 != 0)
			if (dayInt == 29)
				return false;
	}

	return true;
}

// This helper function trims leading and trailing whitespaces from the input.
std::string trim(const std::string& input)
{
	// find the first non-whitespace character
	size_t start = input.find_first_not_of(" \t");
	// npos (no-position) means no matches
	if (start == std::string::npos)
		return ""; // If only whitespace characters, return empty string.
	 // find the last non-whitespace character
	size_t end = input.find_last_not_of(" \t");
	return input.substr(start, end - start + 1);
}

// Returns a boolean to indicate conversion success.
bool convertToFloat(const std::string &floatString, float &floatValue)
{
	// put the string into a stringstream and then extract it as a float
	std::stringstream ss(floatString);
	ss >> floatValue;
	// check that no characters remain in the stringstream.
	// .fail() occurs when floatString is empty/whitespace/non-digits.
	// if there is partial extraction, it is still considered a success,
	// so we must also check for eof.
	if (ss.fail() || !ss.eof())
		return false;
	// handle float overflow
	if (floatValue == std::numeric_limits<float>::infinity() || floatValue == -std::numeric_limits<float>::infinity())
		return false;
	return true;
}

// default constructor
BitcoinExchange::BitcoinExchange()
{
	// std::cout << "BitcoinExchange object default constructor called." << std::endl;

	// opening csvFile
	std::ifstream csvFile("data.csv");
	if (!csvFile.is_open())
		throw CsvFileOpenException();

	std::string line;
	int lineCount = 1;
	while (std::getline(csvFile, line))
	{
		// .find() returns the position of the first character of the first match.
		// If no matches were found, the function returns string::npos.
		size_t commaPosition = line.find(",");

		// skip over first line (header row)
		if (lineCount == 1 || commaPosition == std::string::npos)
		{
			// If comma not found, there are two possibilities:
			// 1) empty line
			// 2) line was not formatted correctly
			if (commaPosition == std::string::npos)
			{
				line = trim(line);
				if (line != "")
					std::cout << YELLOW << "Line " << lineCount << ": missing comma." << RESET << std::endl;
			}
			// clear contents of the string
			line.clear();
			lineCount++;
			continue;
		}
		std::string date;
		std::string exchangeRate;
		date = trim(line.substr(0, commaPosition));
		// without specifying second parameter to substr, the function will grab everything
		// up until the end of the string.
		exchangeRate = trim(line.substr(commaPosition + 1));
		float exchangeRateFloat = 0;
		bool validDate = validateDate(date);
		bool validFloat = convertToFloat(exchangeRate, exchangeRateFloat);
		if (!validDate || !validFloat)
		{
			if (!validDate)
				std::cout << YELLOW << "Line " << lineCount << ": invalid date format : " << date << RESET << std::endl;
			if (!validFloat)
				std::cout << YELLOW << "Line " << lineCount << ": invalid exchangeRate format : " << exchangeRate << RESET << std::endl;
			line.clear();
			lineCount++;
			continue;
		}
		_csvDatabase[date] = exchangeRateFloat;
		lineCount++;
	}
}

// copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	// std::cout << "BitcoinExchange object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	// std::cout << "BitcoinExchange object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
		this->_csvDatabase = src._csvDatabase;
	return *this;
}

// destructor
BitcoinExchange::~BitcoinExchange()
{
	// std::cout << "BitcoinExchange object destructor called." << std::endl;
}

float getExchangeRate(std::string date, std::map<std::string, float> _csvDatabase)
{
	// std::lower_bound returns an iterator pointing to the first element in the range [first,last)
	// which does not compare less than val (i.e. element is >= val).
	// Subject: If the date used in the input does not exist in your DB then you
	// 			must use the closest date contained in your DB. Be careful to use the
	// 			lower date and not the upper one.
	std::map<std::string, float>::iterator it = _csvDatabase.lower_bound(date);
	// it->first (key - date); it->second (value - exchange rate)
	if (it == _csvDatabase.end() || it->first != date)
	{
		// this means the date precedes the first entry in the csv file.
		if (it == _csvDatabase.begin())
			return 0;
		// these conditions indicate we have the upper date so we move the iterator backwards
		// to get the lower date.
		--it;
	}
	// if iterator has not been shifted, that means we get the rate for the exact date.
	return it->second;
}

void BitcoinExchange::evaluate(std::string filename)
{
	// opening inputFile
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
		throw InputFileOpenException();

	std::string line;
	int lineCount = 1;
	while (std::getline(inputFile, line))
	{
		// .find() returns the position of the first character of the first match.
		// If no matches were found, the function returns string::npos.
		size_t barPosition = line.find("|");

		// skip over first line (header row)
		if (lineCount == 1 || barPosition == std::string::npos)
		{
			// If bar not found, there are two possibilities:
			// 1) empty line
			// 2) line was not formatted correctly
			if (barPosition == std::string::npos)
			{
				line = trim(line);
				if (line != "")
					std::cout << YELLOW << "Error: bad input => " << line << RESET << std::endl;
			}
			// clear contents of the string
			line.clear();
			lineCount++;
			continue;
		}
		std::string date;
		std::string value;
		date = trim(line.substr(0, barPosition));
		// without specifying second parameter to substr, the function will grab everything
		// up until the end of the string.
		value = trim(line.substr(barPosition + 1));
		float valueFloat = 0;
		bool validDate = validateDate(date);
		bool validFloat = convertToFloat(value, valueFloat);
		if (!validDate || !validFloat || valueFloat < 0 || valueFloat > 1000)
		{
			if (!validDate || !validFloat)
				std::cout << YELLOW << "Error: bad input => " << line << RESET << std::endl;
			if (valueFloat < 0)
				std::cout << YELLOW << "Error: not a positive number." << RESET << std::endl;
			if (valueFloat > 1000)
				std::cout << YELLOW << "Error: too large a number." << RESET << std::endl;
			line.clear();
			lineCount++;
			continue;
		}
		float result = getExchangeRate(date, _csvDatabase) * valueFloat;
		std::cout << date << " => " << valueFloat << " = " << result << std::endl;
		lineCount++;
	}
}

const char *BitcoinExchange::CsvFileOpenException::what() const throw()
{
	return "Error: .csv file could not be opened.";
}

const char *BitcoinExchange::InputFileOpenException::what() const throw()
{
	return "Error: input file could not be opened.";
}

