/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:21:09 by etien             #+#    #+#             */
/*   Updated: 2025/03/05 13:52:28 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// 				hitPoints	energyPoints	attackDamage
// ClapTrap			10			10				0
// ScavTrap			100			50				20
// FragTrap			100			100				30
// DiamondTrap		100			50				30
// 					Frag		Scav			Frag

// ClapTrap constructor initializes _hitPoints, _energyPoints, _attackDamage.
// ScavTrap constructor reassigns _hitPoints, _energyPoints, _attackDamage.
// FragTrap constructor overwrites _hitPoints, _energyPoints, _attackDamage.
// DiamondTrap constructor may modify them again.
// This explains why you always see the last constructor in the chain (FragTrap in this case) setting the final values.
// tl;dr: One set of three variables, but re-initialized multiple times.

// default constructor
// The base class controls its own members, so they must be initialized in the base class constructor.
// The derived class can only modify inherited members inside the constructor body (not the initializer list).
DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap object default constructor called." << std::endl;
	this->_name = "Default DiamondTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	this->_maxHitPoints = 100;
}

// custom constructor
// If you don't specify ClapTrap(name), the compiler will try to call the default ClapTrap constructor,
// DiamondTrap inherits from ClapTrap, meaning it relies on ClapTrap's functionality.
// The base class must be fully initialized before the derived class can use it.
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << "DiamondTrap object (" << this->_name << ") constructor called." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	this->_maxHitPoints = 100;
}

// copy constructor
// If ClapTrap(src) not specified, ClapTrap object default constructor will be called.
// The order of base class initialization in the constructor must match the order in which
// they are declared in the class.
DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	std::cout << "DiamondTrap object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << "DiamondTrap object copy assignment operator called." << std::endl;
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
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap object destructor called." << std::endl;
}

void DiamondTrap::whoAmI()
{
	ClapTrap::_name = this->_name + "_clap_name";
	std::cout
	<< "DiamondTrap " << this->_name << "'s "
	<< "ClapTrap name is " << ClapTrap::_name << "."
	<< std::endl
	<< std::endl;
}
