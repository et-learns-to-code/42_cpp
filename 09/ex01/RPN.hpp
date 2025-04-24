/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:31:46 by etien             #+#    #+#             */
/*   Updated: 2025/04/24 14:01:24 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <sstream> // istringstream
#include <stack>

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

class RPN
{
	private:
		std::stack <int> _intStack;

		void performOperation(char c);

	public:
		// OCF
		RPN();
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
		~RPN();

		void calculate(std::string expression);

		// exception classes are typically nested classes
		class InvalidOperandException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class IncompleteExpressionException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class InsufficientOperandsException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class DivisionByZeroException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
