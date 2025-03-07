/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:00:04 by etien             #+#    #+#             */
/*   Updated: 2025/03/05 17:19:54 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// default constructor
Animal::Animal()
{
	std::cout << "Animal object default constructor called." << std::endl;
	this->_type = "Animal";
}

// copy constructor
Animal::Animal(const Animal &src)
{
	std::cout << "Animal object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Animal object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
		this->_type = src.getType();
	return *this;
}

// destructor
Animal::~Animal()
{
	std::cout << "Animal object destructor called." << std::endl;
}

std::string Animal::getType() const
{
	return this->_type;
}

void Animal::makeSound() const
{
	std::cout << "* animal sounds *" << std::endl;
}
