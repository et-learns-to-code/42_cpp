/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:08:39 by etien             #+#    #+#             */
/*   Updated: 2025/03/05 12:58:56 by etien            ###   ########.fr       */
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
	return (this->_value > other.getRawBits());
}

bool Fixed::operator<(Fixed const &other) const
{
	return (this->_value < other.getRawBits());
}

bool Fixed::operator>=(Fixed const &other) const
{
	return (this->_value >= other.getRawBits());
}

bool Fixed::operator<=(Fixed const &other) const
{
	return (this->_value <= other.getRawBits());
}

bool Fixed::operator==(Fixed const &other) const
{
	return (this->_value == other.getRawBits());
}

bool Fixed::operator!=(Fixed const &other) const
{
	return (this->_value != other.getRawBits());
}

Fixed Fixed::operator+(Fixed const &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(Fixed const &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(Fixed const &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(Fixed const &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

// Pre-increment (++x) should modify the current instance and
// return a reference to *this.
// Post-increment (x++) should return a copy of the instance
// before modifying it.
// Different function signatures:
// - Pre-increment does not take any parameters and returns a
//   reference to *this.
// - Post-increment takes a dummy int parameter.

// What does "increase or decrease the fixed-point value from the smallest representable ϵ" mean?
// In fixed-point representation, the smallest increment is not 1, but rather 1 / (1 << _fraction).
// Example: _fraction = 8 (which means shifting by 8, or 256)
// The smallest representable step (ϵ) in fixed-point arithmetic is 1 / 256 = 0.00390625.
// If _value is incremented by 1, the actual float value increases by ϵ = 1 / 256.
// ϵ is increment/decrement of the smallest possible step in fixed-point precision.

// pre-increment
Fixed &Fixed::operator++()
{
	this->_value++;
	return (*this);
}

// post-increment
Fixed Fixed::operator++(int)
{
	Fixed prev = *this;
	this->_value++;
	return prev;
}

// pre-decrement
Fixed &Fixed::operator--()
{
	this->_value--;
	return (*this);
}

// post-decrement
Fixed Fixed::operator--(int)
{
	Fixed prev = *this;
	this->_value--;
	return prev;
}

// The non-const version is for modifiable objects.
// The const version is for read-only objects.
// The reason min and max are static is that they do not operate on a specific instance of Fixed.
// Instead, they take two Fixed instances as arguments and return one of them.
// A static member function min that takes as parameters two references on fixed-point
// numbers, and returns a reference to the smallest one.
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

// A static member function min that takes as parameters two references to constant
// fixed-point numbers, and returns a reference to the smallest one.
Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b) ? a : b;
}

// A static member function max that takes as parameters two references on fixed-point
// numbers, and returns a reference to the greatest one.
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

// A static member function max that takes as parameters two references to constant
// fixed-point numbers, and returns a reference to the greatest one.
Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
	return (out << fixed.toFloat());
}
