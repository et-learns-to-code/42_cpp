/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:24:57 by etien             #+#    #+#             */
/*   Updated: 2025/02/18 17:42:37 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name),_weapon(weapon)
{
	std::cout
	<< "HumanA (" << this->_name << ") created with "
	<< this->_weapon.getType() << "."
	<< std::endl;
}

HumanA::~HumanA()
{
	std::cout
	<< "HumanA (" << this->_name << ") destroyed."
	<< std::endl;
}

void HumanA::attack()
{
	std::cout
	<< this->_name << " attacks with their "
	<< this->_weapon.getType()
	<< std::endl;
}
