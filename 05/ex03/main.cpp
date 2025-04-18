/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:17:30 by etien             #+#    #+#             */
/*   Updated: 2025/04/18 18:04:10 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

int main()
{
	Intern someRandomIntern;
	AForm *scf;
	AForm *rrf;
	AForm *ppf;
	AForm *invalid;

	try
	{
		std::cout << GREEN << "\nTEST - INTERN MAKEFORM()\n" << RESET << std::endl;
		std::cout << GREEN << "- ShrubberyCreationForm" << RESET << std::endl;
		scf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
		std::cout << *scf << std::endl;

		std::cout << GREEN << "- RobotomyRequestForm" << RESET << std::endl;
		rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
		std::cout << *rrf << std::endl;

		std::cout << GREEN << "- PresidentialPardonForm" << RESET << std::endl;
		ppf = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
		std::cout << *ppf << std::endl;

		std::cout << GREEN << "- InvalidForm" << RESET << std::endl;
		invalid = someRandomIntern.makeForm("InvalidForm", "Bender");
		std::cout << *invalid << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << "\n" << RESET << std::endl;
	}

	delete scf;
	delete rrf;
	delete ppf;
	return 0;
}
