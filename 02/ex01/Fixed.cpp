/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:08:39 by etien             #+#    #+#             */
/*   Updated: 2025/02/25 12:01:29 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

// initialize static variable
const int Fixed::_fraction = 8;

Fixed::Fixed() : _value(0)
{
	std::cout << "Fixed object default constructor called." << std::endl;
}

Fixed::Fixed(const int value)
{

}

Fixed::Fixed(const float value)
{

}

// A copy constructor is a special constructor used to create a new
// object as a copy of an existing object. Its purpose is to copy the
// values from an existing instance (src) into the new instance.
// *this = src will call the copy assignment operator function.
Fixed::Fixed(Fixed const &src)
{
	std::cout << "Fixed object copy constructor called." << std::endl;
	*this = src;
}

// When you overload the assignment operator (=), you are customizing
// what happens when = is used on objects of your class.
// Even inside the copy constructor, when you do *this = src;, the operator=
// is triggered because *this is an object of the same class.
// Since operator= is overloaded, it overrides default assignment behavior and
// executes your custom logic instead.
Fixed &Fixed::operator=(Fixed const &src)
{
	std::cout << "Fixed object copy assignment operator called." << std::endl;
	this->_value = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Fixed object destructor called." << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called." << std::endl;
	return this->_value;
}

void Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}
