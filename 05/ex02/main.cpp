/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:17:30 by etien             #+#    #+#             */
/*   Updated: 2025/04/01 18:25:52 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <cstdlib> // srand()
#include <ctime> // time()

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void testShrubberyCreationForm()
{
	std::cout << GREEN << "------------------------------------- TEST: SHRUBBERY CREATION FORM -------------------------------------" << RESET << std::endl << std::endl;

	std::cout << GREEN << "- default constructor" << RESET << std::endl;
	ShrubberyCreationForm test;
	std::cout << test << std::endl;

	std::cout << GREEN << "- copy constructor" << RESET << std::endl;
	ShrubberyCreationForm copy(test);
	std::cout << copy << std::endl;

	std::cout << GREEN << "- custom constructor" << RESET << std::endl;
	ShrubberyCreationForm shrubbery("home");
	std::cout << shrubbery << std::endl;

	Bureaucrat senior("Senior", 137);
	std::cout << senior << std::endl;
	Bureaucrat junior("Junior", 138);
	std::cout << junior << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "- form execution failure (unsigned form)" << RESET << std::endl;
	senior.executeForm(shrubbery);
	std::cout << shrubbery << std::endl;

	std::cout << GREEN << "- form execution failure (unqualified bureaucrat)" << RESET << std::endl;
	senior.signForm(shrubbery);
	junior.executeForm(shrubbery);
	std::cout << shrubbery << std::endl;

	std::cout << GREEN << "- form execution success" << RESET << std::endl;
	senior.executeForm(shrubbery);
	std::cout << shrubbery << std::endl;
}

void testRobotomyRequestForm()
{
	std::cout << GREEN << "------------------------------------- TEST: ROBOTOMY REQUEST FORM -------------------------------------" << RESET << std::endl << std::endl;

	std::cout << GREEN << "- default constructor" << RESET << std::endl;
	RobotomyRequestForm test;
	std::cout << test << std::endl;

	std::cout << GREEN << "- copy constructor" << RESET << std::endl;
	RobotomyRequestForm copy(test);
	std::cout << copy << std::endl;

	std::cout << GREEN << "- custom constructor" << RESET << std::endl;
	RobotomyRequestForm robotomy("Robot");
	std::cout << robotomy << std::endl;

	Bureaucrat senior("Senior", 45);
	std::cout << senior << std::endl;
	Bureaucrat junior("Junior", 46);
	std::cout << junior << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "- form execution failure (unsigned form)" << RESET << std::endl;
	senior.executeForm(robotomy);
	std::cout << robotomy << std::endl;

	std::cout << GREEN << "- form execution failure (unqualified bureaucrat)" << RESET << std::endl;
	senior.signForm(robotomy);
	junior.executeForm(robotomy);
	std::cout << robotomy << std::endl;

	std::cout << GREEN << "- form execution success" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << BLUE <<  "Robotomy attempt " << i + 1 << ":" << RESET << std::endl;
		senior.executeForm(robotomy);
		std::cout << std::endl;
	}
	std::cout << robotomy << std::endl;
}

void testPresidentialPardonForm()
{
	std::cout << GREEN << "------------------------------------- TEST: PRESIDENTIAL PARDON FORM -------------------------------------" << RESET << std::endl << std::endl;

	std::cout << GREEN << "- default constructor" << RESET << std::endl;
	PresidentialPardonForm test;
	std::cout << test << std::endl;

	std::cout << GREEN << "- copy constructor" << RESET << std::endl;
	PresidentialPardonForm copy(test);
	std::cout << copy << std::endl;

	std::cout << GREEN << "- custom constructor" << RESET << std::endl;
	PresidentialPardonForm pardon("Criminal");
	std::cout << pardon << std::endl;

	Bureaucrat senior("Senior", 5);
	std::cout << senior << std::endl;
	Bureaucrat junior("Junior", 6);
	std::cout << junior << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "- form execution failure (unsigned form)" << RESET << std::endl;
	senior.executeForm(pardon);
	std::cout << pardon << std::endl;

	std::cout << GREEN << "- form execution failure (unqualified bureaucrat)" << RESET << std::endl;
	senior.signForm(pardon);
	junior.executeForm(pardon);
	std::cout << pardon << std::endl;

	std::cout << GREEN << "- form execution success" << RESET << std::endl;
	senior.executeForm(pardon);
	std::cout << pardon << std::endl;
}

int main()
{
	// Random seeding for Robotomy Request Form.
	// By default, rand() produces the same sequence every time your program runs.
	// To ensure randomness, seed the random number generator with current time
	// to ensure different results each run.
	srand(time(NULL));

	testShrubberyCreationForm();
	testRobotomyRequestForm();
	testPresidentialPardonForm();
	return 0;
}
