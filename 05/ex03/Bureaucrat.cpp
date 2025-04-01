/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:02:32 by etien             #+#    #+#             */
/*   Updated: 2025/04/01 18:18:49 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// default constructor
Bureaucrat::Bureaucrat() : _name("Default Bureaucrat"), _grade(150)
{
	// std::cout << "Bureaucrat object default constructor called." << std::endl;
}

// copy constructor
// _name variable is const so it must be initialized in initialization list
Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName())
{
	// std::cout << "Bureaucrat object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
// _name variable is const so it cannot be reassigned
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	// std::cout << "Bureaucrat object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
		this->_grade = src.getGrade();
	return *this;
}

// destructor
Bureaucrat::~Bureaucrat()
{
	// std::cout << "Bureaucrat object destructor called." << std::endl;
}

// custom constructor
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	// std::cout << "Bureaucrat object custom constructor called." << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

// decrement grade because a lower value means a higher grade.
void Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

// increment grade because a higher value means a lower grade.
void Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << "." << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName()
			<< " because: " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << "." << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << this->_name << " couldn't execute " << form.getName()
			<< " because: " << e.what() << std::endl;
	}
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
