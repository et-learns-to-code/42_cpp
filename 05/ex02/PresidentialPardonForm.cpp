/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:41:48 by etien             #+#    #+#             */
/*   Updated: 2025/03/31 20:17:50 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// default constructor
// _target() will implicitly initialize _target to an empty string
PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5), _target()
{
	// std::cout << "PresidentialPardonForm object default constructor called." << std::endl;
}

// copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
: AForm(src)
{
	// std::cout << "PresidentialPardonForm object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	// std::cout << "PresidentialPardonForm object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
		this->_target = src.getTarget();
	return *this;
}

// destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "PresidentialPardonForm object destructor called." << std::endl;
}

// custom constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	// std::cout << "PresidentialPardonForm object custom constructor called." << std::endl;
}

// getter
std::string PresidentialPardonForm::getTarget() const
{
	return this->_target;
}
