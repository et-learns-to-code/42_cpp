/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:38:49 by etien             #+#    #+#             */
/*   Updated: 2025/03/05 17:39:58 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// default constructor
WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal object default constructor called." << std::endl;
	this->_type = "WrongAnimal";
}

// copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "WrongAnimal object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "WrongAnimal object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
		this->_type = src.getType();
	return *this;
}

// destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal object destructor called." << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "* wrong animal sounds *" << std::endl;
}
