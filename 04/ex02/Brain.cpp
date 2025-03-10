/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:22:09 by etien             #+#    #+#             */
/*   Updated: 2025/03/10 14:26:47 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// default constructor
Brain::Brain()
{
	std::cout << "Brain object default constructor called." << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "Head empty. No thoughts.";
}

// copy constructor
Brain::Brain(const Brain &src)
{
	std::cout << "Brain object copy constructor called." << std::endl;
	*this = src;
}

// In C++, when you assign an array, the compiler actually treats the array as a pointer to its first element.
// So doing this->_ideas = src._ideas; is equivalent to copying a pointer, not the actual array contents.
// This means both objects will now point to the same array in memory.
// Changes to one object's _ideas will affect the other.

// assignment operator
Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Brain object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
		// loop through the array and manually copy over the contents of the array
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src.getIdea(i);
	return *this;
}

// destructor
Brain::~Brain()
{
	std::cout << "Brain object destructor called." << std::endl;
}

const std::string &Brain::getIdea(const int &index) const
{
	if (index >= 0 && index < 100)
		return this->_ideas[index];
	return this->_ideas[0];
}

void Brain::setIdea(const std::string &idea, const int &index)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
}
