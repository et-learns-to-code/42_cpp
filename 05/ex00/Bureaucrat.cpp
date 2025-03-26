/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:02:32 by etien             #+#    #+#             */
/*   Updated: 2025/03/26 18:17:05 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// default constructor
Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat object default constructor called." << std::endl;
	this->_type = "Bureaucrat";
}

// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	std::cout << "Bureaucrat object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
	{
		this->_type = src.getType();
		// deleting a nullptr is safe in C++.
		// it will not cause crashes or undefined behaviour.
		// delete old brain to avoid memory leaks
		delete this->_brain;
		// deep copy of Brain by creating a new instance
		this->_brain = new Brain(*src.getBrain());
	}
	return *this;
}

// destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat object destructor called." << std::endl;
	delete this->_brain;
}


const std::string Bureaucrat::getName() const
{

}

int Bureaucrat::getGrade() const
{

}

void Bureaucrat::incrementGrade()
{
	this->_grade++;
}

void Bureaucrat::decrementGrade()
{
	this->_grade--;
}


const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

// insertion operator overload
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	// <name>, bureaucrat grade <grade>.
	return (out << bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade() << ".");
}
