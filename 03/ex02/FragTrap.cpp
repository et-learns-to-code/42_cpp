/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:21:09 by etien             #+#    #+#             */
/*   Updated: 2025/03/05 13:43:55 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// default constructor
FragTrap::FragTrap()
{
	std::cout << "FragTrap object default constructor called." << std::endl;
	this->_name = "Default FragTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_maxHitPoints = 100;
}

// custom constructor
// If you don't specify ClapTrap(name), the compiler will try to call the default ClapTrap constructor,
// FragTrap inherits from ClapTrap, meaning it relies on ClapTrap's functionality.
// The base class must be fully initialized before the derived class can use it.
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap object (" << this->_name << ") constructor called." << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_maxHitPoints = 100;
}

// copy constructor
// If ClapTrap(src) not specified, ClapTrap object default constructor will be called.
FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << "FragTrap object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "FragTrap object copy assignment operator called." << std::endl;
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
FragTrap::~FragTrap()
{
	std::cout << "FragTrap object destructor called." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout
	<< "FragTrap " << this->_name
	<< " wants to give you an epic high five. Engage?"
	<< std::endl
	<< std::endl;
}
