/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:02:32 by etien             #+#    #+#             */
/*   Updated: 2025/03/31 19:19:02 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// default constructor
Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(50), _gradeToExecute(100)
{
	// std::cout << "Form object default constructor called." << std::endl;
}

// copy constructor
// const variables must be initialized in initialization list
Form::Form(const Form &src)
: _name(src.getName()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
	// std::cout << "Form object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
// const variables cannot be reassigned
Form &Form::operator=(const Form &src)
{
	// std::cout << "Form object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
		this->_isSigned = src.getIsSigned();
	return *this;
}

// destructor
Form::~Form()
{
	// std::cout << "Form object destructor called." << std::endl;
}

static int validateGrade(int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
	return grade;
}

// custom constructor
Form::Form(std::string name, int gradeToSign, int gradeToExecute)
: _name(name), _isSigned(false), _gradeToSign(validateGrade(gradeToSign)), _gradeToExecute(validateGrade(gradeToExecute))
{
	// std::cout << "Form object custom constructor called." << std::endl;
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getIsSigned() const
{
	return this->_isSigned;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

// insertion operator overload
std::ostream &operator<<(std::ostream &out, const Form &form)
{
	// <name>, form grade <grade>.
	return (out << YELLOW
		<< "_name: " << form.getName()
		<< "; _isSigned: " << form.getIsSigned() << ";" << std::endl
		<< "_gradeToSign: " << form.getGradeToSign() << ";" << std::endl
		<< "_gradeToExecute: " << form.getGradeToExecute()
		<< "." << RESET);
}
