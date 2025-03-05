/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:00:04 by etien             #+#    #+#             */
/*   Updated: 2025/03/05 11:19:15 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// default constructor
ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap object default constructor called." << std::endl;
	this->_name = "Default ScavTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_maxHitPoints = 100;
}

// copy constructor
// If ClapTrap(src) not specified, ClapTrap object default constructor will be called.
ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << "ScavTrap object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap object copy assignment operator called." << std::endl;
	// check for self-assignment
	// getters and setters not used here to avoid unnecessary function calls.
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
		this->_maxHitPoints = src._maxHitPoints;
	}
	return *this;
}

// destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap object destructor called." << std::endl;
}
