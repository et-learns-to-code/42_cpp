/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:54:55 by etien             #+#    #+#             */
/*   Updated: 2025/02/18 16:52:09 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

// Initialize name variable to an empty string because name
// is a string object. NULL is only applicable for pointers
// and initializing a string object to NULL would cause a
// compiler error.
Zombie::Zombie() :_name("")
{
	std::cout
	<< "Zombie (default) created."
	<< std::endl;
}

// Keeping this function for comparison purposes to show that
// it isn't called when the zombie horde is created.
Zombie::Zombie( std::string name )
{
	this->_name = name;
	std::cout
	<< "Zombie (" << this->_name << ") created."
	<< std::endl;
}

Zombie::~Zombie()
{
	std::cout
	<< "Zombie (" << this->_name << ") destroyed."
	<< std::endl;
}

void Zombie::announce( void )
{
	std::cout
	<< this->_name << ": BraiiiiiiinnnzzzZ..."
	<< std::endl;
}

void Zombie::setName( std::string name)
{
	this->_name = name;
}
