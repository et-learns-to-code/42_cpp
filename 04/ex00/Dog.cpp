/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:19:35 by etien             #+#    #+#             */
/*   Updated: 2025/03/10 14:31:45 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// default constructor
Dog::Dog()
{
	std::cout << "Dog object default constructor called." << std::endl;
	this->_type = "Dog";
}

// copy constructor
// If Animal(src) not specified, Animal object default constructor will be called.
Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << "Dog object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
		this->_type = src.getType();
	return *this;
}

// destructor
Dog::~Dog()
{
	std::cout << "Dog object destructor called." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << this->_type << " barks." << std::endl;
}
