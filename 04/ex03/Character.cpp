/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:14:54 by etien             #+#    #+#             */
/*   Updated: 2025/03/11 14:04:57 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// default constructor
Character::Character() : _name("default")
{
	std::cout << "Character object default constructor called." << std::endl;
	// set the array of AMateria pointers to null to avoid undefined behaviour
	for (int i = 0; i < _inventorySize; i++)
		this->_inventory[i] = NULL;
}

// copy constructor
Character::Character(const Character &src)
{
	std::cout << "Character object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
Character &Character::operator=(const Character &src)
{
	std::cout << "Character object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
	{
		this->_name = src.getName();
		for (int i = 0; i < _inventorySize; i++)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
			if (src._inventory[i])
				// "While assigning a Materia to another, copying the type doesn’t make sense."
				// Instead of copying its type, you should create a new instance using the clone() method.
				// clone() ensures the correct subclass (e.g., Ice, Cure) is copied, preserving the correct behavior.
				this->_inventory[i] = src._inventory[i]->clone();
		}
	}
	return *this;
}

// destructor
Character::~Character()
{
	std::cout << "Character object destructor called." << std::endl;
	for (int i = 0; i < _inventorySize; i++)
		delete this->_inventory[i];
}

// custom constructor
Character::Character(std::string name) : _name(name)
{
	std::cout << "Character object (" << this->_name << ") custom constructor called." << std::endl;
	// set the array of AMateria pointers to null to avoid undefined behaviour
	for (int i = 0; i < _inventorySize; i++)
		this->_inventory[i] = NULL;
}

// override of pure virtual functions in base class
std::string const & Character::getName() const
{
	return this->_name;
}

// The Character possesses an inventory of 4 slots, which means 4 Materias at most.
// The inventory is empty at construction. They equip the Materias in the first empty slot
// they find. This means, in this order: from slot 0 to slot 3.
void Character::equip(AMateria* m)
{
	// null check
	if (!m)
		return;
	// check that Materia has not already been equipped in a different slot
	for (int i = 0; i < _inventorySize; i++)
	{
		if (this->_inventory[i] == m)
		{
			std::cout << this->_name << " already has " << m->getType() << " equipped at slot " << i << "." << std::endl;
			return;
		}
	}
	// equip Materia at first empty slot
	for (int i = 0; i < _inventorySize; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			std::cout << this->_name << " equipped " << m->getType() << " at slot " << i << "." << std::endl;
			return;
		}
	}
	std::cout << this->_name << "'s inventory is full." << std::endl;
}

// In case they try to add a Materia to a full inventory, or use/unequip
// an unexisting Materia, don’t do anything (but still, bugs are forbidden).
// The unequip() member function must NOT delete the Materia!
void Character::unequip(int idx)
{
	if (idx < 0 || idx >= _inventorySize)
	{
		std::cout << this->_name << ": Invalid slot index." << std::endl;
		return;
	}
	if (!this->_inventory[idx])
	{
		std::cout << this->_name << " does not have Materia equipped at slot " << idx << "." << std::endl;
		return;
	}
	// statement must be printed before setting to null otherwise getType will be called on null value.
	std::cout
		<< this->_name << " has unequipped " << this->_inventory[idx]->getType()
		<< " from slot " << idx << "." << std::endl;
	this->_inventory[idx] = NULL;
}

// The character will use Materia on a target.
void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= _inventorySize)
	{
		std::cout << this->_name << ": Invalid slot index." << std::endl;
		return;
	}
	if (!this->_inventory[idx])
	{
		std::cout << this->_name << " does not have Materia equipped at slot " << idx << "." << std::endl;
		return;
	}
	std::cout << this->_name << " ";
	this->_inventory[idx]->use(target);
}
