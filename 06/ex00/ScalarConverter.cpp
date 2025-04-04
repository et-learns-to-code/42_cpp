/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:44:56 by etien             #+#    #+#             */
/*   Updated: 2025/04/04 12:04:07 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cstdlib> // atoi

// default constructor
ScalarConverter::ScalarConverter()
{
	// std::cout << "ScalarConverter object default constructor called." << std::endl;
}

// copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	// std::cout << "ScalarConverter object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	// std::cout << "ScalarConverter object copy assignment operator called." << std::endl;
	(void) src;
	return *this;
}

// destructor
ScalarConverter::~ScalarConverter()
{
	// std::cout << "ScalarConverter object destructor called." << std::endl;
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

// This function will print out the conversion results for pseudo literals:
// -inff, +inff, nanf
// -inf, +inf, nan
bool detectPseudoLiterals(const std::string &input)
{
	if (input != "-inff" && input != "+inff" && input != "nanf" &&
		input != "-inf" && input != "+inf" && input != "nan")
		return false;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (input == "-inff" || input == "-inf")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (input == "+inff" || input == "+inf")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (input == "nanf" || input == "nan")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	return true;
}

// This function checks that the string is only composed of
// digits, '-', '.' and 'f' (for floats).
bool validNumericCharacters(const std::string &input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		char c = input[i];
		if (!isdigit(c) && c != '-' && c != '.' && c != 'f')
			return false;
	}
	return true;
}

// This function checks the syntax involving '-', '.' and 'f'.
// '-': occur once and must be at the start of the string.
// '.': occur once and must be sandwiched by digits.
// 'f': occur once and must be at the end of the string and
//      string must also have a decimal point.
bool validNumericSyntax(const std::string &input)
{
	int negativeCount = 0;
	int dotCount = 0;
	int fCount = 0;

	for (size_t i = 0; i < input.size(); i++)
	{
		char c = input[i];
		if (c == '-')
			negativeCount++;
		if (c == '.')
			dotCount++;
		if (c == 'f')
			fCount++;
	}
	// all special characters should only occur once
	if (negativeCount > 1 || dotCount > 1 || fCount > 1)
		return false;
	// basic negative number format: -d (min 2 characters)
	if (negativeCount == 1 && input.size() < 2)
		return false;
	// basic double format: d.d (min 3 characters)
	if (dotCount == 1 && input.size() < 3)
		return false;
	// basic float number format: d.df (min 4 characters)
	if (fCount == 1 && input.size() < 4)
		return false;
	// floats must always have a decimal point
	if (fCount == 1 && dotCount == 0)
		return false;

	size_t inputFront = input[0];
	size_t inputBack = input[input.size() - 1];

	// negative sign must be at the start of the string
	if (negativeCount == 1 && inputFront != '-')
		return false;
	// 'f' must be at the end of the string
	if (fCount == 1 && inputBack != 'f')
		return false;
	// decimal point cannot be at the start or end of the string.
	if (dotCount == 1 && (inputFront == '.' || inputBack == '.'))
		return false;
	// decimal point must be sandwiched by digits
	if (dotCount == 1)
	{
		size_t dotPos = input.find('.');
		char prev = input[dotPos - 1];
		char next = input[dotPos + 1];
		if (!isdigit(prev) || !isdigit(next))
			return false;
	}
	return true;
}

bool isInteger(const std::string &input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		// std::string is a wrapper around a dynamic character array, which means
		// you can access its characters using array-style indexing ([]).
		char c = input[i];
		// an integer should only be composed of digits and an optional sign
		if (!isdigit(c) && c != '-')
			return false;
	}
	return true;
}

// after passing the preliminary checks, the only difference between a
// float and a double is the 'f' character behind.
bool isFloat(const std::string &input)
{
	if (input[input.size() - 1] != 'f')
		return false;
	return true;
}

void printChar(int i)
{
	if (i < 0 || i > 127 || !std::isprint(i))
		std::cout << "char: Non displayable";
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
}

ScalarType detectType(const std::string &input)
{
	// if input is an empty string
	if (input.size() == 0 ||
		!validNumericCharacters(input) || !validNumericSyntax(input))
		return INVALID;
	else if (isInteger(input))
		return INT;
	else if (isFloat(input))
		return FLOAT;
	return DOUBLE;
}

void printInvalidNumber()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void ScalarConverter::convert(std::string input)
{
	input = trim(input);
	if (detectPseudoLiterals(input))
		return;
 	ScalarType type = detectType(input);
	if (type == INVALID)
		std::cout << "Invalid" << std::endl;
	else if (type == INT)
		std::cout << "Integer" << std::endl;
	else if (type == FLOAT)
		std::cout << "Float" << std::endl;
	else if (type == DOUBLE)
		std::cout << "Double" << std::endl;
	// if (type == INVALID)
	// {
	// 	printInvalidNumber();
	// 	return;
	// }
	// printChar(atoi(input.c_str()));

}

