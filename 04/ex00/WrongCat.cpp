/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:24:59 by etien             #+#    #+#             */
/*   Updated: 2025/03/05 17:38:12 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// default constructor
WrongCat::WrongCat()
{
	std::cout << "WrongCat object default constructor called." << std::endl;
	this->_type = "WrongCat";
}

// copy constructor
// If WrongCat(src) not specified, WrongCat object default constructor will be called.
WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	std::cout << "WrongCat object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
WrongCat &WrongCat::operator=(const WrongCat &src)
{
	std::cout << "WrongCat object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
		this->_type = src.getType();
	return *this;
}

// destructor
WrongCat::~WrongCat()
{
	std::cout << "WrongCat object destructor called." << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << this->_type << "meows." << std::endl;
}
