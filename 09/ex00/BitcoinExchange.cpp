/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:02:32 by etien             #+#    #+#             */
/*   Updated: 2025/04/23 13:58:21 by etien            ###   ########.fr       */
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
	// Find the first non-whitespace character
	size_t start = input.find_first_not_of(" \t");
	// npos (no-position) means no matches
	if (start == std::string::npos)
		return ""; // If only whitespace characters, return empty string.
	 // Find the last non-whitespace character
	size_t end = input.find_last_not_of(" \t");
	return input.substr(start, end - start + 1);
}

// returns a boolean to indicate conversion success.
bool convertToFloat(const std::string &exchangeRate, float &floatValue)
{
	// put the string into a stringstream and then extract it as a float
	std::stringstream ss(exchangeRate);
	ss >> floatValue;
	// check that no characters remain in the stringstream
	// .fail() occurs when exchangeRate is empty/whitespace/non-digits.
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
	std::ifstream csvFile("test.csv");
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
					std::cout << RED << "Line " << lineCount << ": missing comma." << RESET << std::endl;
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
		float floatValue = 0;
		bool validDate = validateDate(date);
		bool validFloat = convertToFloat(exchangeRate, floatValue);
		if (!validDate || !validFloat)
		{
			if (!validDate)
				std::cout << RED << "Line " << lineCount << ": invalid date format : " << date << RESET << std::endl;
			if (!validFloat)
				std::cout << RED << "Line " << lineCount << ": invalid exchangeRate format : " << exchangeRate << RESET << std::endl;
			line.clear();
			lineCount++;
			continue;
		}
		csvDatabase[date] = floatValue;
		std::cout << "date: " << date << ", exchangeRate: " << exchangeRate << std::endl;
		lineCount++;
	}
}

// copy constructor
// _name variable is const so it must be initialized in initialization list
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	// std::cout << "BitcoinExchange object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
// _name variable is const so it cannot be reassigned
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	// std::cout << "BitcoinExchange object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
		this->csvDatabase = src.csvDatabase;
	return *this;
}

// destructor
BitcoinExchange::~BitcoinExchange()
{
	// std::cout << "BitcoinExchange object destructor called." << std::endl;
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
		float floatValue = 0;
		bool validDate = validateDate(date);
		bool validFloat = convertToFloat(value, floatValue);
		if (!validDate || !validFloat || floatValue < 0 || floatValue > 1000)
		{
			if (!validDate || !validFloat)
				std::cout << YELLOW << "Error: bad input => " << line << RESET << std::endl;
			if (floatValue < 0)
				std::cout << YELLOW << "Error: not a positive number." << RESET << std::endl;
			if (floatValue > 1000)
				std::cout << YELLOW << "Error: too large a number." << RESET << std::endl;
			line.clear();
			lineCount++;
			continue;
		}
		std::cout << "date: " << date << ", value: " << value << std::endl;
		lineCount++;
	}
}

const char *BitcoinExchange::CsvFileOpenException::what() const throw()
{
	return ".csv file could not be opened.";
}

const char *BitcoinExchange::InputFileOpenException::what() const throw()
{
	return "Input file could not be opened.";
}

const char *BitcoinExchange::InvalidDateException::what() const throw()
{
	return "Grade is too high.";
}

