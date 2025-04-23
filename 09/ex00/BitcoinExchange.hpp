/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:31:46 by etien             #+#    #+#             */
/*   Updated: 2025/04/23 13:28:31 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib> // atoi
#include <sstream> // stringstream
#include <limits>

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

class BitcoinExchange
{
	private:
		// stores date, exchange rate pairs
		std::map <std::string, float> csvDatabase;

	public:
		// OCF
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange();

		void evaluate(std::string txtFile);

		// exception classes are typically nested classes
		class CsvFileOpenException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class InputFileOpenException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class InvalidDateException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
