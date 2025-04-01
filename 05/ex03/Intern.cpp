/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:34:01 by etien             #+#    #+#             */
/*   Updated: 2025/04/01 21:57:30 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// default constructor
Intern::Intern()
{
	// std::cout << "Intern object default constructor called." << std::endl;
}

// copy constructor
Intern::Intern(const Intern &src)
{
	// std::cout << "Intern object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
Intern &Intern::operator=(const Intern &src)
{
	// std::cout << "Intern object copy assignment operator called." << std::endl;
	return *this;
}

// destructor
Intern::~Intern()
{
	// std::cout << "Intern object destructor called." << std::endl;
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	// array of form names
	std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	// array of function pointers to static functions
	// Non-static member function pointers (Intern::*form_ptrs[]) require an object.
	// Static function pointers (*form_ptrs[]) don’t require an object and work as intended.
	AForm *(*makeForms[])(const std::string &target) =
	{
		makeShrubberyCreationForm,
		makeRobotomyRequestForm,
		makePresidentialPardonForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			AForm *form = makeForms[i](target);
			std::cout << "Intern creates " << form->getName() << "." << std::endl;
			return form;
		}
	}
	throw AForm::InvalidFormException();
}

// static factory helper functions for makeForm
// A static factory function is a function that creates and returns instances of a class
// without requiring an object of the class itself.
AForm *Intern::makeShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}
