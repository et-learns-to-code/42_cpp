/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:24:59 by etien             #+#    #+#             */
/*   Updated: 2025/03/10 14:31:29 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// default constructor
Cat::Cat()
{
	std::cout << "Cat object default constructor called." << std::endl;
	this->_type = "Cat";
}

// copy constructor
// If Animal(src) not specified, Animal object default constructor will be called.
Cat::Cat(const Cat &src) : Animal(src)
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
		this->_type = src.getType();
	return *this;
}

// destructor
Cat::~Cat()
{
	std::cout << "Cat object destructor called." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << this->_type << " meows." << std::endl;
}
