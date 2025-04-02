/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:17:30 by etien             #+#    #+#             */
/*   Updated: 2025/04/02 13:01:52 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <cstdlib> // srand()
#include <ctime> // time()

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
		std::cout << GREEN << "TEST - INTERN MAKEFORM()" << RESET << std::endl;
		std::cout << std::endl;
		std::cout << GREEN << "- ShrubberyCreationForm" << RESET << std::endl;
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		std::cout << *scf << std::endl;

		std::cout << GREEN << "- RobotomyRequestForm" << RESET << std::endl;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;

		std::cout << GREEN << "- PresidentialPardonForm" << RESET << std::endl;
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		std::cout << *ppf << std::endl;

		std::cout << GREEN << "- invalid form" << RESET << std::endl;
		invalid = someRandomIntern.makeForm("invalid form", "Bender");
		std::cout << *invalid << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	delete scf;
	delete rrf;
	delete ppf;
	return 0;
}
