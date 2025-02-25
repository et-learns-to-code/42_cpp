/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:08:39 by etien             #+#    #+#             */
/*   Updated: 2025/02/25 19:25:07 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>

// initialize static variable
const int Fixed::_fraction = 8;

Fixed::Fixed() : _value(0)
{
}

// Using bit shifting for conversion instead of a ft_power helper function
// will preserve floating-point accuracy because eveything is done in
// integer space, so there is no rounding issue.
Fixed::Fixed(const int value) : _value(value << this->_fraction)
{
}

// roundf() ensures correct rounding before converting to an integer.
// roundf() is a function from the cmath library that rounds a floating-point 
// number to the nearest integer (but still returns a float).
// Without roundf, conversion to an integer would simply truncate the number
// without accounting for the round up/down that the decimal portion would
// typically need.
// Floats are stored in IEEE 754 format, which means they have a sign bit, 
// exponent, and mantissa. Unlike integers, bitwise operations (like <<) 
// don't shift the actual value but instead modify the binary representation, 
// which can lead to incorrect results.
// The workaround is to bit shift 1 (an integer) then multiply it with the
// float value.
Fixed::Fixed(const float value) : _value(roundf(value * (1 << this->_fraction)))
{
}

// A copy constructor is a special constructor used to create a new
// object as a copy of an existing object. Its purpose is to copy the
// values from an existing instance (src) into the new instance.
// *this = src will call the copy assignment operator function.
Fixed::Fixed(Fixed const &src)
{
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
	this->_value = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits( void ) const
{
	return this->_value;
}

void Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

// 1 >> _fraction is always 0 when _fraction is 8
// so we use division instead of multiplication
float Fixed::toFloat( void ) const
{
	return (this->_value / (float)(1 << this->_fraction));
}

int Fixed::toInt( void ) const
{
	return (this->_value >> this->_fraction);
}

bool Fixed::operator>(Fixed const &other) const
{
	return (this->_value > other._value);
}

bool Fixed::operator<(Fixed const &other) const
{
	return (this->_value < other._value);	
}

bool Fixed::operator>=(Fixed const &other) const
{
	return (this->_value >= other._value);	
}

bool Fixed::operator<=(Fixed const &other) const
{
	return (this->_value <= other._value);	
}

bool Fixed::operator==(Fixed const &other) const
{
	return (this->_value == other._value);	
}

bool Fixed::operator!=(Fixed const &other) const
{
	return (this->_value != other._value);	
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
	return (out << fixed.toFloat());
}
