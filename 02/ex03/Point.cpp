/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:37:27 by etien             #+#    #+#             */
/*   Updated: 2025/02/26 15:37:22 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Default constructor
Point::Point() : _x(0), _y(0) {}

// Float constructor
Point::Point(const float x, const float y) : _x(x), _y(y) {}

// Copy constructor
Point::Point(const Point &src)
{
	*this = src;
}

// Since _x and _y are const, their values must be initialized at
// the moment of construction and cannot be modified later.
// The copy assignment operator is meant to modify an existing object,
// but because _x and _y are immutable, you cannot reassign them.
// Copy assignment operator overload
Point &Point::operator=(const Point &src)
{
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
