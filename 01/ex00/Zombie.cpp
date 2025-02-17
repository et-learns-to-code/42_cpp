/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:54:55 by etien             #+#    #+#             */
/*   Updated: 2025/02/17 17:19:41 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie( std::string name )
{
	this->_name = name;
	std::cout
	<< "Zombie object (" << this->_name << ") created."
	<< std::endl;
}

Zombie::~Zombie()
{
	std::cout
	<< "Zombie object (" << this->_name << ") destroyed."
	<< std::endl;
}

void Zombie::announce( void )
{
	std::cout
	<< this->_name << ": BraiiiiiiinnnzzzZ..."
	<< std::endl;
}
