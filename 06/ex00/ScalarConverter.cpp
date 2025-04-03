/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:44:56 by etien             #+#    #+#             */
/*   Updated: 2025/04/03 18:23:53 by etien            ###   ########.fr       */
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
	for (std::size_t i = 0; i < input.size(); i++)
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
// 'f': occur once and must be at the end of the string.
bool validNumericSyntax(const std::string &input)
{
	int negativeCount = 0;
	int dotCount = 0;
	int fCount = 0;

	for (std::size_t i = 0; i < input.size(); i++)
	{
		char c = input[i];
		if (c == '-')
			negativeCount++;
		if (c == '.')
			dotCount++;
		if (c == 'f')
			fCount++;
	}
	if (negativeCount > 1 || dotCount > 1 || fCount > 1)
		return false;
	if (negativeCount == 1 && input.front() != '-')
		return false;
	if (fCount == 1 && input.back() != 'f')
		return false;
	if (dotCount == 1 && )

	return true;
}

bool isInteger(const std::string &input)
{
	for (std::size_t i = 0; i < input.size(); i++)
	{
		char c = input[i];
		if (!isdigit(c))
			return false;
	}
	return true;
}

bool isDouble(const std::string &input)
{
	// for (std::size_t i = 0; i < input.size(); i++)
	// {
	// 	char c = input[i];
	// 	if (!isdigit(c))
	// 		return false;
	// }
	// return true;
}

bool isFloat(const std::string &input)
{
	// .back() accesses the last character
	if (input.back() == 'f')
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
	if (input.size() == 0)
		return INVALID;
	// std::string is a wrapper around a dynamic character array, which means
	// you can access its characters using array-style indexing ([]).
	else if (input.size() == 1 && !isdigit(input[0]))
		return CHAR;
	else if (!validNumericCharacters(input) || !validNumericSyntax(input))
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
	{
		printInvalidNumber();
		return;
	}
	printChar(atoi(input.c_str()));

}

