/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:44:56 by etien             #+#    #+#             */
/*   Updated: 2025/04/04 16:47:19 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cstdlib> // atoi
#include <limits> // for numeric limits to check for overflow

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

void printInvalidNumber()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

// This function will print out the conversion results for pseudo literals:
// -inff, +inff, nanf
// -inf, +inf, nan
bool detectPseudoLiterals(const std::string &input)
{
	if (input != "-inff" && input != "+inff" && input != "nanf" &&
		input != "-inf" && input != "+inf" && input != "nan")
		return false;
	if (input == "nanf" || input == "nan")
	{
		printInvalidNumber();
		return true;
	}
	// -inff, -inf, +inff, +inf
	bool isNegative = (input[0] == '-');
	std::string infFloat = isNegative ? "-inff" : " +inff";
	std::string infDouble = isNegative ? "-inf" : " +inf";
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << infFloat << std::endl;
	std::cout << "double: " << infDouble << std::endl;
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

// Returns the type of the input: INVALID, CHAR, INT, FLOAT or DOUBLE.
ScalarType detectType(const std::string &input)
{
	// if input is an empty string
	if (input.size() == 0)
		return INVALID;
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

void printChar(double value)
{
	if (value < 0 || value > 127 || !std::isprint(value))
		std::cout << "char: Non displayable";
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

// std::numeric_limits<int>::min() ✅ → Smallest possible integer (e.g., -2147483648 for int)
// std::numeric_limits<int>::max() ✅ → Largest possible integer (e.g., 2147483647 for int)
void printInt(double value)
{
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

// std::numeric_limits<float>::min() → Smallest positive value (not the most negative!)
// std::numeric_limits<float>::max() → Largest positive value
// std::numeric_limits<float>::lowest() → Most negative floating-point number
void printFloat(double value)
{
	if (value < std::numeric_limits<float>::lowest() || value > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(value) << std::endl;
}

// double overflow is already checked in try-catch block
void printDouble(double value)
{
	std::cout << "double: " << value << std::endl;
}

// safe conversion to all types because a displayable character in the terminal
// should be between 32 and 126.
void convertForChar(const std::string &input)
{
	// conversion necessary because static_cast expects a numeric type, not a pointer.
	int asciiValue = static_cast<int>(input[0]);

	std::cout << "char: '" << input[0] << "'" << std::endl;
	std::cout << "int: " << asciiValue << std::endl;
	std::cout << "float: " << static_cast<float>(asciiValue) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(asciiValue) << ".0" << std::endl;
}

void convertForType(ScalarType type, std::string input)
{
	if (type == INVALID)
	{
		printInvalidNumber();
		return;
	}
	else if (type == CHAR)
	{
		convertForChar(input);
		return;
	}
	// handle INT, FLOAT and DOUBLE together
	if (type == FLOAT)
		input = input.substr(0, input.size() - 1);
	try
	{
		// convert string to a double
		double value = std::stod(input);
		printChar(value);
		printInt(value);
		printFloat(value);
		printDouble(value);
	}
	// If no conversion could be performed, an 1) invalid_argument exception is thrown.
	// If the value read is out of the range of representable values by a double (in some library implementations,
	// this includes underflows), an 2) out_of_range exception is thrown.
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		printInvalidNumber();
	}
}

void ScalarConverter::convert(std::string input)
{
	// if condition to allow single spaces
	if (input.size() > 1)
		input = trim(input);
	if (detectPseudoLiterals(input))
		return;
 	ScalarType type = detectType(input);
	convertForType(type, input);
	// if (type == INVALID)
	// 	std::cout << "Invalid" << std::endl;
	// else if (type == CHAR)
	// 	std::cout << "Char" << std::endl;
	// else if (type == INT)
	// 	std::cout << "Integer" << std::endl;
	// else if (type == FLOAT)
	// 	std::cout << "Float" << std::endl;
	// else if (type == DOUBLE)
	// 	std::cout << "Double" << std::endl;
}

