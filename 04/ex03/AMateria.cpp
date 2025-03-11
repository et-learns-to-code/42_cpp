/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:26:58 by etien             #+#    #+#             */
/*   Updated: 2025/03/11 15:34:39 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// default constructor
AMateria::AMateria() : _type("AMateria")
{
	// std::cout << "AMateria object default constructor called." << std::endl;
}

// copy constructor
AMateria::AMateria(const AMateria &src)
{
	// std::cout << "AMateria object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
AMateria &AMateria::operator=(const AMateria &src)
{
	// std::cout << "AMateria object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
		this->_type = src.getType();
	return *this;
}

// destructor
AMateria::~AMateria()
{
	// std::cout << "AMateria object destructor called." << std::endl;
}

// custom constructor
AMateria::AMateria(std::string const & type) : _type(type)
{
	// std::cout << "AMateria object (" << this->_type << ") custom constructor called." << std::endl;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* uses Materia on " << target.getName() << " *" << std::endl;
}
