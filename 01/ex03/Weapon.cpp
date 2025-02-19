/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:25:22 by etien             #+#    #+#             */
/*   Updated: 2025/02/19 10:57:07 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon() {}

// const ensures that the caller cannot modify the returned string.
// Without const, the caller could do something like:
// weapon.getType() = "new type";  // This would modify _type without any setter
// By returning a const reference, the compiler prevents this.

// The function returns a reference to the existing _type member rather than
// making a new copy. References are more efficient, especially for frequently
// accessed values.
const std::string& Weapon::getType()
{
	return this->_type;
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}
