/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:37:27 by etien             #+#    #+#             */
/*   Updated: 2025/02/26 18:19:26 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Default constructor
Point::Point() : _x(0), _y(0) {}

// Float constructor
Point::Point(const float x, const float y) : _x(x), _y(y) {}

// Copy constructor
// The copy constructor is modified. It usually relies on the copy assignment
// operator overload to correctly assign the variables. However, the variables
// are const and cannnot be reassigned. The solution is to initialize the
// variables in an initialization list.
Point::Point(const Point &src) : _x(src.getX()), _y(src.getY()) {}

// Copy assignment operator overload
// Since _x and _y are const, their values must be initialized at
// the moment of construction and cannot be modified later.
// The copy assignment operator is meant to modify an existing object,
// but because _x and _y are immutable, you cannot reassign them.
// Simply to fulfill the Orthodox Canonical form, we create a redundant
// copy assignment operator overload.
Point &Point::operator=(const Point &src)
{
	(void) src;
	return *this;
}

// Destructor
Point::~Point() {}

Fixed const &Point::getX() const
{
	return this->_x;
}

Fixed const &Point::getY() const
{
	return this->_y;
}

std::ostream &operator<<(std::ostream &out, Point const &point)
{
	return (out << "(" << point.getX() << ", " << point.getY() << ")");
}
