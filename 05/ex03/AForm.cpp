/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:02:32 by etien             #+#    #+#             */
/*   Updated: 2025/04/02 11:20:03 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// default constructor
AForm::AForm() : _name("Default AForm"), _isSigned(false), _gradeToSign(50), _gradeToExecute(100)
{
	// std::cout << "AForm object default constructor called." << std::endl;
}

// copy constructor
// const variables must be initialized in initialization list
AForm::AForm(const AForm &src)
: _name(src.getName()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
	// std::cout << "AForm object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
// const variables cannot be reassigned
AForm &AForm::operator=(const AForm &src)
{
	// std::cout << "AForm object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
		this->_isSigned = src.getIsSigned();
	return *this;
}

// destructor
AForm::~AForm()
{
	// std::cout << "AForm object destructor called." << std::endl;
}

static int validateGrade(int grade)
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > 150)
		throw AForm::GradeTooLowException();
	return grade;
}

// custom constructor
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
: _name(name), _isSigned(false), _gradeToSign(validateGrade(gradeToSign)), _gradeToExecute(validateGrade(gradeToExecute))
{
	// std::cout << "AForm object custom constructor called." << std::endl;
}

std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getIsSigned() const
{
	return this->_isSigned;
}

int AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->_isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	beExecuted();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form has not been signed.";
}

const char *AForm::InvalidFormException::what() const throw()
{
	return "Form does not exist.";
}

// insertion operator overload
std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	return (out << YELLOW
		<< "_name: " << form.getName() << ";" << std::endl
		<< "_isSigned: " << form.getIsSigned() << ";" << std::endl
		<< "_gradeToSign: " << form.getGradeToSign() << ";" << std::endl
		<< "_gradeToExecute: " << form.getGradeToExecute() << ";" << std::endl
		<< "_target: " << form.getTarget()
		<< "." << std::endl << RESET);
}
