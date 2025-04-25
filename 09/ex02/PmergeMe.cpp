/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:02:32 by etien             #+#    #+#             */
/*   Updated: 2025/04/25 08:24:44 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// default constructor
PmergeMe::PmergeMe()
{
	// std::cout << "PmergeMe object default constructor called." << std::endl;
}

// copy constructor
PmergeMe::PmergeMe(const PmergeMe &src)
{
	// std::cout << "PmergeMe object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	// std::cout << "PmergeMe object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
	{
		this->_intVector = src._intVector;
		this->_intDeque = src._intDeque;
	}
	return *this;
}

// destructor
PmergeMe::~PmergeMe()
{
	// std::cout << "PmergeMe object destructor called." << std::endl;
}

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

// This helper function trims leading and trailing whitespaces from the input.
std::string trim(const std::string& input)
{
	// find the first non-whitespace character
	size_t start = input.find_first_not_of(" \t");
	// npos (no-position) means no matches
	if (start == std::string::npos)
		return ""; // If only whitespace characters, return empty string.
	 // find the last non-whitespace character
	size_t end = input.find_last_not_of(" \t");
	return input.substr(start, end - start + 1);
}


// 1) trim the string
// 2) check that it only contains digits and is a positive integer (no '-' allowed)
// 3) convert to long and test that the integer does not overflow
// 4) check for existing duplicates in the vector
// 5) add the number (as an integer) to the vector
void PmergeMe::createVector(char **av)
{
	while (*av)
	{
		std::string str(*av);
		str = trim(str);
		// hasOnlyDigits() will flag negative numbers too because of their negative sign
		if (!hasOnlyDigits(str))
			throw InvalidNumberException(str);
		// The third parameter is the number base. '10' indicates decimal.
		// strtol is called to check overflow before static_cast to int.
		long testInt = strtol(str.c_str(), NULL, 10);
		if (testInt > INT_MAX || testInt < INT_MIN)
			throw IntegerOverflowException(str);
		// std::find() returns an iterator to the found element or vec.end() if not found.
		if (std::find(_intVector.begin(), _intVector.end(), testInt) != _intVector.end())
			throw DuplicateNumberException(str);
		_intVector.push_back(static_cast<int>(testInt));		
		av++;
	}	
	for (std::vector<int>::iterator it = _intVector.begin(); it != _intVector.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
}

void PmergeMe::compare(char **av)
{	
	createVector(av);
}

PmergeMe::ParsingException::ParsingException(std::string err) : _message(err) {}

PmergeMe::ParsingException::~ParsingException() throw() {}

const char *PmergeMe::ParsingException::what() const throw()
{
	return _message.c_str();
}

PmergeMe::InvalidNumberException::InvalidNumberException(std::string number)
: PmergeMe::ParsingException("Error: Invalid number : " + number) {}

PmergeMe::IntegerOverflowException::IntegerOverflowException(std::string number)
: PmergeMe::ParsingException("Error: Integer overflow : " + number) {}

PmergeMe::NegativeNumberException::NegativeNumberException(std::string number)
: PmergeMe::ParsingException("Error: Negative number : " + number) {}

PmergeMe::DuplicateNumberException::DuplicateNumberException(std::string number)
: PmergeMe::ParsingException("Error: Duplicate number : " + number) {}
