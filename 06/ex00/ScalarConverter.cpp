/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:44:56 by etien             #+#    #+#             */
/*   Updated: 2025/04/03 14:53:26 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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


// ScalarType detectType(const std::string &input)
// {
// }


void ScalarConverter::convert(std::string input)
{
	input = trim(input);
	if (detectPseudoLiterals(input))
		return;
	// ScalarType type = detectType(input);
}

