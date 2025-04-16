/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:30:46 by etien             #+#    #+#             */
/*   Updated: 2025/04/16 15:54:40 by etien            ###   ########.fr       */
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
		this->_intSet = src.getIntSet();
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

const std::set<int> &Span::getIntSet() const
{
	return this->_intSet;
}

const unsigned int &Span::getN() const
{
	return this->_N;
}

void Span::addNumber(int number)
{
	if (_intSet.size() >= _N)
		throw Span::ContainerFullException();
	// use insert() instead of push_back() for std::set
	// insert() returns a std::pair<iterator, bool>, where:
	// - iterator points to the inserted (or already existing) element.
	// - bool is true if the insertion happened, false if the value already existed.
	// std::pair is a class template that provides a way to store two heterogeneous objects as a single unit.
	std::pair<std::set<int>::iterator, bool> result = _intSet.insert(number);
	if (!result.second)
		std::cout << number << " was already in the set." << std::endl;
}

// This function will return the shortest span.
// Since elements in a set are already arranged in ascending order,
// we iterate through the container and compute the difference between
// adjacent elements. We return the smallest difference/span found.
// long data type used to handle span = (INT_MAX - INT_MIN) edge case.
long Span::shortestSpan()
{
	if (_intSet.size() == 0 || _intSet.size() == 1)
		throw Span::SpanNotFoundException();
	// read-only iterator that will cause compile error if you try
	// to modify the element.
	std::set<int>::const_iterator elem1 = _intSet.begin();
	std::set<int>::const_iterator elem2 = ++_intSet.begin();
	// initialize to -1 because span will be absolute values (i.e. positive).
	long shortestSpan = -1;
	while (elem2 != _intSet.end())
	{
		// explicitly convert element 1 and 2 to long before performing subtraction
		// to prevent overflow.
		// static_cast is a compile-time operation and does not add any runtime overhead.
		long long1 = static_cast<long>(*elem1);
		long long2 = static_cast<long>(*elem2);
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
	if (_intSet.size() == 0 || _intSet.size() == 1)
		throw Span::SpanNotFoundException();
	// dereference the iterator to access the element.
	long smallestNumber = *(_intSet.begin());
	// move the end iterator one position back to get the last element.
	long largestNumber = *(--_intSet.end());
	long longestSpan = largestNumber - smallestNumber;
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
