/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:02:32 by etien             #+#    #+#             */
/*   Updated: 2025/03/28 17:27:50 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// default constructor
Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(50), _gradeToExecute(100)
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

static int

// custom constructor
Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false)
{
	// std::cout << "Form object custom constructor called." << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	this->_gradeToSign = gradeToSign;
	this->_gradeToExecute = gradeToExecute;
}

const std::string Form::getName() const
{
	return this->_name;
}

int Form::getGrade() const
{
	return this->_grade;
}

// decrement grade because a lower value means a higher grade.
void Form::incrementGrade()
{
	if (this->_grade == 1)
		throw Form::GradeTooHighException();
	this->_grade--;
}

// increment grade because a higher value means a lower grade.
void Form::decrementGrade()
{
	if (this->_grade == 150)
		throw Form::GradeTooLowException();
	this->_grade++;
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
	return (out << form.getName() << ", form grade "
		<< form.getGrade() << ".");
}
