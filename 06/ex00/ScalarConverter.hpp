/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:59:59 by etien             #+#    #+#             */
/*   Updated: 2025/04/07 16:14:09 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib> // atoi, strtol, strtof, strtod
#include <limits> // for numeric limits to check for overflow
#include <climits> // LONG_MAX, LONG_MIN, HUGE_VALF, HUGE_VAL
#include <cerrno> // errno, ERANGE
#include <cmath> // floor

#define GREEN "\033[32m"
#define RESET "\033[0m"

enum ScalarType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

class ScalarConverter
{
	private:
		// OCF - put into private so that class cannot be instantiated by users
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);
		~ScalarConverter();

	public:
		static void convert(std::string input);
};

#endif
