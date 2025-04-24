/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:30:46 by etien             #+#    #+#             */
/*   Updated: 2025/04/25 06:57:19 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// copy constructor
Span::Span(const Span &src)
{
	// std::cout << "Span object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
Span &Span::operator=(const Span &src)
{
	// std::cout << "Span object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
	{
		// no need to manually deep copy for standard containers
		// unless containers hold pointers.
		this->_intVector = src.getIntVector();
		this->_N = src.getN();
	}
	return *this;
}

// destructor
Span::~Span()
{
	// std::cout << "Span object destructor called." << std::endl;
}

// parameterized constructor
Span::Span(unsigned int n) : _N(n)
{
	// std::cout << "Span object parameterized constructor called." << std::endl;
}

// getters
const std::vector<int> &Span::getIntVector() const
{
	return this->_intVector;
}

const unsigned int &Span::getN() const
{
	return this->_N;
}

void Span::addNumber(int number)
{
	if (_intVector.size() >= _N)
		throw Span::ContainerFullException();
	_intVector.push_back(number);
}

// This function will sort the vector in ascending order and remove duplicate values.
void Span::sortVector()
{
	// std::sort sorts the elements in the range [first, last) in non-descending order
	// std::unique moves consecutive duplicates to the end and returns an iterator to the new logical end.
	// erase(...) trims the vector so it only keeps unique values.
	// erase([first,last)) will trim a range of elements.
	// begin() and end() are always updated after a std::vector::erase().
	std::sort(_intVector.begin(), _intVector.end());
	std::vector<int>::iterator newEnd = std::unique(_intVector.begin(), _intVector.end());
	_intVector.erase(newEnd, _intVector.end());
}

// This function will return the shortest span.
// We iterate through the container and compute the difference between
// adjacent elements. We return the smallest difference/span found.
// long data type used to handle span = (INT_MAX - INT_MIN) edge case.
long Span::shortestSpan()
{
	if (_intVector.size() == 0 || _intVector.size() == 1)
		throw Span::SpanNotFoundException();
	sortVector();
	// read-only iterator that will cause compile error if you try
	// to modify the element.
	std::vector<int>::const_iterator elem1 = _intVector.begin();
	std::vector<int>::const_iterator elem2 = ++_intVector.begin();
	// initialize to -1 because span will be absolute values (i.e. positive).
	long shortestSpan = -1;
	while (elem2 != _intVector.end())
	{
		// explicitly convert element 1 and 2 to long before performing subtraction
		// to prevent overflow.
		// static_cast is a compile-time operation and does not add any runtime overhead.
		long long1 = *elem1;
		long long2 = *elem2;
		long testSpan = std::abs(long2 - long1);
		if (shortestSpan == -1 || testSpan < shortestSpan)
			shortestSpan = testSpan;
		elem1++;
		elem2++;
	}
	return shortestSpan;
}

// This function returns the longest span, which is simply
// the difference between the greatest and smallest element.
long Span::longestSpan()
{
	if (_intVector.size() == 0 || _intVector.size() == 1)
		throw Span::SpanNotFoundException();
	sortVector();
	// dereference the iterator to access the element.
	long smallestNumber = *(_intVector.begin());
	// move the end iterator one position back to get the last element.
	long largestNumber = *(--_intVector.end());
	long longestSpan = std::abs(largestNumber - smallestNumber);
	return longestSpan;
}

const char *Span::ContainerFullException::what() const throw()
{
	return "Cannot add number. Container is full.";
}

const char *Span::SpanNotFoundException::what() const throw()
{
	return "Not enough elements to find a span.";
}
