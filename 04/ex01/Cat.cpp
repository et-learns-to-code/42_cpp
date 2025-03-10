/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:24:59 by etien             #+#    #+#             */
/*   Updated: 2025/03/10 14:39:30 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// default constructor
Cat::Cat() : _brain(new Brain())
{
	std::cout << "Cat object default constructor called." << std::endl;
	this->_type = "Cat";
}

// copy constructor
// If Animal(src) not specified, Animal object default constructor will be called.
// Initialize brain pointer to NULL otherwise deleting brain in operator overload
// will produce error messages in valgrind.
Cat::Cat(const Cat &src) : Animal(src), _brain(NULL)
{
	std::cout << "Cat object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat object copy assignment operator called." << std::endl;
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
Cat::~Cat()
{
	std::cout << "Cat object destructor called." << std::endl;
	delete this->_brain;
}

void Cat::makeSound() const
{
	std::cout << this->_type << " meows." << std::endl;
}

Brain *Cat::getBrain() const
{
	return this->_brain;
}
