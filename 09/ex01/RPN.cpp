/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:02:32 by etien             #+#    #+#             */
/*   Updated: 2025/04/24 14:05:04 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// default constructor
RPN::RPN()
{
	// std::cout << "RPN object default constructor called." << std::endl;
}

// copy constructor
RPN::RPN(const RPN &src)
{
	// std::cout << "RPN object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
RPN &RPN::operator=(const RPN &src)
{
	// std::cout << "RPN object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
		this->_intStack = src._intStack;
	return *this;
}

// destructor
RPN::~RPN()
{
	// std::cout << "RPN object destructor called." << std::endl;
}

void RPN::performOperation(char c)
{
	if (_intStack.size() < 2)
		throw InsufficientOperandsException();
	// read the value
	int rhs = _intStack.top();
	// remove it from the stack
	_intStack.pop();
	int lhs = _intStack.top();
	_intStack.pop();
	int result = 0;
	if (c == '+')
		result = lhs + rhs;
	else if (c == '-')
		result = lhs - rhs;
	else if (c == '*')
		result = lhs * rhs;
	else if (c == '/')
	{
		if (rhs == 0)
			throw DivisionByZeroException();
		result = lhs / rhs;
	}
	_intStack.push(result);
	// std::cout << lhs << " " << c << " " << rhs << " = " << result << std::endl;
}

void RPN::calculate(std::string expression)
{
	// Using an istringstream to extract digits and operators one by one while skipping whitespace.
	std::istringstream iss(expression);
	char c;
	while (iss >> c)
	{
		if (std::isdigit(c))
		{
			int digit = c - '0';
			_intStack.push(digit);
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
			performOperation(c);
		else
			throw InvalidOperandException();
	}
	if (_intStack.size() != 1)
		throw IncompleteExpressionException();
	std::cout << _intStack.top() << std::endl;

}

const char *RPN::InvalidOperandException::what() const throw()
{
	return "Error: Invalid operand.";
}

const char *RPN::IncompleteExpressionException::what() const throw()
{
	return "Error: Incomplete expression.";
}

const char *RPN::InsufficientOperandsException::what() const throw()
{
	return "Error: Insufficient operands.";
}

const char *RPN::DivisionByZeroException::what() const throw()
{
	return "Error: Division by zero.";
}
