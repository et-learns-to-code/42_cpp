/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:42:29 by etien             #+#    #+#             */
/*   Updated: 2025/04/01 12:26:16 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <cstdlib> // srand(), rand()
#include <ctime> // time()

// default constructor
// _target() will implicitly initialize _target to an empty string
RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), _target("target")
{
	// std::cout << "RobotomyRequestForm object default constructor called." << std::endl;
}

// copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
: AForm(src)
{
	// std::cout << "RobotomyRequestForm object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	// std::cout << "RobotomyRequestForm object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
		this->_target = src.getTarget();
	return *this;
}

// destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "RobotomyRequestForm object destructor called." << std::endl;
}

// custom constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	// std::cout << "RobotomyRequestForm object custom constructor called." << std::endl;
}

// getter
std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void RobotomyRequestForm::beExecuted() const
{
	std::cout << "* drilling noises *" << std::endl;

	// By default, rand() produces the same sequence every time your program runs.
	// To ensure randomness, seed the random number generator with current time
	// to ensure different results each run.
	srand(time(NULL));

	// rand() % 2 generates either 0 or 1 randomly to simulate a 50% success rate
	bool successful = rand() % 2 == 0;

	if (successful)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy for " << this->_target << " has failed." << std::endl;
}
