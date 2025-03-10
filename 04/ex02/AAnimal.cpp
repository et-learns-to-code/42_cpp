/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:00:04 by etien             #+#    #+#             */
/*   Updated: 2025/03/10 15:28:05 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// default constructor
AAnimal::AAnimal()
{
	std::cout << "AAnimal object default constructor called." << std::endl;
	this->_type = "AAnimal";
}

// copy constructor
AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "AAnimal object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
AAnimal &AAnimal::operator=(const AAnimal &src)
{
	std::cout << "AAnimal object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
		this->_type = src.getType();
	return *this;
}

// destructor
AAnimal::~AAnimal()
{
	std::cout << "AAnimal object destructor called." << std::endl;
}

std::string AAnimal::getType() const
{
	return this->_type;
}

void AAnimal::makeSound() const
{
	std::cout << "* animal sounds *" << std::endl;
}
