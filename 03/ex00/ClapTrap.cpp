/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:31:13 by etien             #+#    #+#             */
/*   Updated: 2025/02/28 14:07:21 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap object default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap object (" << this->_name << ") constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap object copy constructor called." << std::endl;
	*this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "ClapTrap object copy assignment operator called." << std::endl;
	// check for self-assignment
	// getters and setters not used here to avoid unnecessary function calls.
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap object destructor called." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0)
	{
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		std::cout
		<< "ClapTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_attackDamage << " points of damage!"
		<< std::endl
		<< "ClapTrap " << this->_name << " has used up one energy point."
		<< std::endl;
		printClapTrapStatus();
	}
	else
	{
		std::cout
		<< "ClapTrap " << this->_name
		<< "is out of energy points!"
		<< std::endl;
		printClapTrapStatus();
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->_hitPoints)
	{
		this->setHitPoints(0);
		std::cout
		<< "ClapTrap " << this->_name << " has died!"
		<< std::endl;
		printClapTrapStatus();
	}
	else
	{
		this->setHitPoints(this->getHitPoints() - amount);
		std::cout
		<< "ClapTrap " << this->_name << " has taken "
		<< amount << " points of damage!"
		<< std::endl;
		printClapTrapStatus();
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 10)
	{
		std::cout
		<< "ClapTrap " << this->_name << " is already at max hit points."
		<< std::endl;
		printClapTrapStatus();
	}
	else if (this->_energyPoints > 0)
	{
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		std::cout
		<< "ClapTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_attackDamage << " points of damage!"
		<< std::endl
		<< "ClapTrap " << this->_name << " has used up one energy point."
		<< std::endl;
		printClapTrapStatus();
	}
	else
	{
		std::cout
		<< "ClapTrap " << this->_name
		<< "is out of energy points!"
		<< std::endl;
		printClapTrapStatus();
	}
}

std::string ClapTrap::getName() const
{
	return this->_name;
}

int ClapTrap::getHitPoints() const
{
	return this->_hitPoints;
}

int ClapTrap::getEnergyPoints() const
{
	return this->_energyPoints;
}

int ClapTrap::getAttackDamage() const
{
	return this->_attackDamage;
}

void ClapTrap::setName(std::string const name)
{
	this->_name = name;
}

void ClapTrap::setHitPoints(int const hitPoints)
{
	this->_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int const energyPoints)
{
	this->_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int const attackDamage)
{
	this->_attackDamage = attackDamage;
}

void ClapTrap::printClapTrapStatus()
{
	std::cout
	<< "HP: " << this->getHitPoints() << ", "
	<< "EP: " << this->getEnergyPoints() << ", "
	<< "AD: " << this->getAttackDamage()
	<< std::endl;
}
