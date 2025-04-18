/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:17:30 by etien             #+#    #+#             */
/*   Updated: 2025/04/18 17:13:53 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

void testDefaultBureaucrat()
{
	std::cout << GREEN << "\nTEST: DEFAULT BUREAUCRAT" << RESET << std::endl;
	Bureaucrat bureaucrat;
	std::cout << bureaucrat << std::endl;
}

void testCopiedBureaucrat()
{
	std::cout << GREEN << "\nTEST: COPIED BUREAUCRAT" << RESET << std::endl;
	Bureaucrat original("Original", 75);
	std::cout << original << std::endl;
	Bureaucrat copycat(original);
	std::cout << copycat << std::endl;
}

void testConstructorGradeTooHigh()
{
	try
	{
		std::cout << GREEN << "\nTEST: CONSTRUCTOR - GRADE TOO HIGH" << RESET << std::endl;
		Bureaucrat alpha("Alpha", 0);
		std::cout << alpha << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void testConstructorGradeTooLow()
{
	try
	{
		std::cout << GREEN << "\nTEST: CONSTRUCTOR - GRADE TOO LOW" << RESET << std::endl;
		Bureaucrat beta("Beta", 151);
		std::cout << beta << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void testIncrementGrade()
{
	try
	{
		std::cout << GREEN << "\nTEST: INCREMENT GRADE" << RESET << std::endl;
		Bureaucrat promoted("Promoted", 3);
		std::cout << promoted << std::endl;
		for (int i = 0; i < 3; i++)
		{
			promoted.incrementGrade();
			std::cout << promoted << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void testDecrementGrade()
{
	try
	{
		std::cout << GREEN << "\nTEST: DECREMENT GRADE" << RESET << std::endl;
		Bureaucrat demoted("Demoted", 148);
		std::cout << demoted << std::endl;
		for (int i = 0; i < 3; i++)
		{
			demoted.decrementGrade();
			std::cout << demoted << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << "\n" << RESET << std::endl;
	}
}

int main()
{
	testDefaultBureaucrat();
	testCopiedBureaucrat();
	testConstructorGradeTooHigh();
	testConstructorGradeTooLow();
	testIncrementGrade();
	testDecrementGrade();
	return 0;
}
