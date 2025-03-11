/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:21:19 by etien             #+#    #+#             */
/*   Updated: 2025/03/11 16:06:36 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// default constructor
MateriaSource::MateriaSource()
{
	// std::cout << "MateriaSource object default constructor called." << std::endl;
	// set the array of AMateria pointers to null to avoid undefined behaviour
	for (int i = 0; i < _templatesSize; i++)
		this->_templates[i] = NULL;
}

// copy constructor
MateriaSource::MateriaSource(const MateriaSource &src)
{
	// std::cout << "MateriaSource object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	// std::cout << "MateriaSource object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
	{
		for (int i = 0; i < _templatesSize; i++)
		{
			delete this->_templates[i];
			this->_templates[i] = NULL;
			if (src._templates[i])
				// "While assigning a Materia to another, copying the type doesn’t make sense."
				// Instead of copying its type, you should create a new instance using the clone() method.
				// clone() ensures the correct subclass (e.g., Ice, Cure) is copied, preserving the correct behavior.
				this->_templates[i] = src._templates[i]->clone();
		}
	}
	return *this;
}

// destructor
MateriaSource::~MateriaSource()
{
	// std::cout << "MateriaSource object destructor called." << std::endl;
	for (int i = 0; i < _templatesSize; i++)
		delete this->_templates[i];
}

// override of pure virtual functions in base class
// Copies the Materia passed as a parameter and stores it in memory so it can be cloned
// later. Like the Character, the MateriaSource can know at most 4 Materias. They
// are not necessarily unique.
void MateriaSource::learnMateria(AMateria *m)
{
	// null check
	if (!m)
		return;
	// equip Materia at first empty slot
	for (int i = 0; i < _templatesSize; i++)
	{
		if (!this->_templates[i])
		{
			this->_templates[i] = m->clone();
			std::cout << m->getType() << " template has been stored at slot " << i << "." << std::endl;
			return;
		}
	}
	std::cout << "unable to store more Materia templates." << std::endl;
}

// Returns a new Materia. The latter is a copy of the Materia previously learned by
// the MateriaSource whose type equals the one passed as parameter. Returns 0 if
// the type is unknown.
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < _templatesSize; i++)
	{
		if (this->_templates[i] && type == this->_templates[i]->getType())
		{
			std::cout << "creating a new " << type << " Materia." << std::endl;
			return this->_templates[i]->clone();
		}
	}
	std::cout << "unable to create Materia. " << type << " is not in templates." << std::endl;
	return 0;
}
