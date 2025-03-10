/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:30:30 by etien             #+#    #+#             */
/*   Updated: 2025/03/10 18:31:31 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// default constructor
Cure::Cure() : AMateria("ice")
{
	std::cout << "Cure object default constructor called." << std::endl;
}

// copy constructor
Cure::Cure(const Cure &src)
{
	std::cout << "Cure object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
Cure &Cure::operator=(const Cure &src)
{
	std::cout << "Cure object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
		this->_type = src.getType();
	return *this;
}

// destructor
Cure::~Cure()
{
	std::cout << "Cure object destructor called." << std::endl;
}

// clone() will return a new instance of the same type
AMateria* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
