/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:21:09 by etien             #+#    #+#             */
/*   Updated: 2025/03/05 13:31:29 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

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

// custom constructor
// If you don't specify ClapTrap(name), the compiler will try to call the default ClapTrap constructor,
// ScavTrap inherits from ClapTrap, meaning it relies on ClapTrap's functionality.
// The base class must be fully initialized before the derived class can use it.
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap object (" << this->_name << ") constructor called." << std::endl;
	this->_name = name;
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
	if (this != &src)
	{
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
		this->_maxHitPoints = src.getMaxHitPoints();
	}
	return *this;
}

// destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap object destructor called." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (checkDeath() || checkEnergyPoints())
		return;
	this->_energyPoints--;
	std::cout
	<< "ScavTrap " << this->_name << " attacks " << target
	<< ", causing " << this->_attackDamage << " points of damage!"
	<< std::endl
	<< "ScavTrap " << this->_name << " has used up one energy point."
	<< std::endl;
	printStatus();
}

void ScavTrap::guardGate()
{
	std::cout
	<< "ScavTrap " << this->_name
	<< " is now in Gatekeeper mode."
	<< std::endl
	<< std::endl;
}
