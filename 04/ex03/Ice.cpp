/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:21:24 by etien             #+#    #+#             */
/*   Updated: 2025/03/10 18:29:33 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// default constructor
Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice object default constructor called." << std::endl;
}

// copy constructor
Ice::Ice(const Ice &src)
{
	std::cout << "Ice object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
Ice &Ice::operator=(const Ice &src)
{
	std::cout << "Ice object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
		this->_type = src.getType();
	return *this;
}

// destructor
Ice::~Ice()
{
	std::cout << "Ice object destructor called." << std::endl;
}

// clone() will return a new instance of the same type
AMateria* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
