/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:25:09 by etien             #+#    #+#             */
/*   Updated: 2025/03/06 14:26:25 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#include "iostream"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	std::cout
	<< "HumanB (" << this->_name << ") created with no weapon."
	<< std::endl;
}

HumanB::~HumanB()
{
	std::cout
	<< "HumanB (" << this->_name << ") destroyed."
	<< std::endl;
}

void HumanB::attack()
{
	if (!this->_weapon)
	{
		std::cout
		<< this->_name << " is unarmed."
		<< std::endl;
	}
	else
	{
		std::cout
		<< this->_name << " attacks with their "
		<< this->_weapon->getType() << "."
		<< std::endl;
	}
}

// The two ampersands (&) here have different meanings:
// 1) Reference type (parameter) — Weapon &weapon:
// The function works with the original Weapon object.
// 2) Address-of operator (assignment) — &weapon:
// Gets the memory address of the Weapon object.
void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
