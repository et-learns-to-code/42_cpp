/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:59:59 by etien             #+#    #+#             */
/*   Updated: 2025/04/04 17:27:35 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib> // atoi, strtod
#include <limits> // for numeric limits to check for overflow
#include <cerrno> // errno, ERANGE

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
