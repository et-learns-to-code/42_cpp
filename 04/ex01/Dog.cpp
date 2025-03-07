/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:19:35 by etien             #+#    #+#             */
/*   Updated: 2025/03/07 17:00:11 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// default constructor
Dog::Dog() : _brain(new Brain())
{
	std::cout << "Dog object default constructor called." << std::endl;
	this->_type = "Dog";
}

// copy constructor
// If Dog(src) not specified, Dog object default constructor will be called.
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
	{
		this->_type = src.getType();
		// deleting a nullptr is safe in C++.
		// it will not cause crashes or undefined behaviour.
		// delete old brain to avoid memory leaks
		delete this->_brain;
		// deep copy of Brain by creating a new instance
		this->_brain = new Brain(*src.getBrain());
	}
	return *this;
}

// destructor
Dog::~Dog()
{
	std::cout << "Dog object destructor called." << std::endl;
	delete this->_brain;
}

void Dog::makeSound() const
{
	std::cout << this->_type << " barks." << std::endl;
}

Brain *Dog::getBrain() const
{
	return this->_brain;
}
