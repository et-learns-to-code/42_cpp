/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:14:54 by etien             #+#    #+#             */
/*   Updated: 2025/03/10 19:17:12 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


// default constructor
Character::Character()
{
	std::cout << "Character object default constructor called." << std::endl;
	this->_type = "Character";
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
		this->_type = src.getType();
	return *this;
}

// destructor
Character::~Character()
{
	std::cout << "Character object destructor called." << std::endl;
}

std::string const & Character::getName() const
{

}

void Character::equip(AMateria* m)
{

}

void Character::unequip(int idx)
{

}

void Character::use(int idx, ICharacter& target)
{

}
