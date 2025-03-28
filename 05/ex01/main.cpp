/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:17:30 by etien             #+#    #+#             */
/*   Updated: 2025/03/28 16:29:11 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

void testDefaultBureaucrat()
{
	std::cout << GREEN << "TEST: DEFAULT BUREAUCRAT" << RESET << std::endl;
	Bureaucrat bureaucrat;
	std::cout << bureaucrat << std::endl;
}

void testCopiedBureaucrat()
{
	std::cout << GREEN << "TEST: COPIED BUREAUCRAT" << RESET << std::endl;
	Bureaucrat original("Original", 75);
	std::cout << original << std::endl;
	Bureaucrat copycat(original);
	std::cout << copycat << std::endl;
}

void testConstructorGradeTooHigh()
{
	try
	{
		std::cout << GREEN << "TEST: CONSTRUCTOR - GRADE TOO HIGH" << RESET << std::endl;
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
		std::cout << GREEN << "TEST: CONSTRUCTOR - GRADE TOO LOW" << RESET << std::endl;
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
		std::cout << GREEN << "TEST: INCREMENT GRADE" << RESET << std::endl;
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
		std::cout << GREEN << "TEST: DECREMENT GRADE" << RESET << std::endl;
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
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

int main()
{
	std::cout << std::endl;
	testDefaultBureaucrat();
	std::cout << std::endl;
	testCopiedBureaucrat();
	std::cout << std::endl;
	testConstructorGradeTooHigh();
	std::cout << std::endl;
	testConstructorGradeTooLow();
	std::cout << std::endl;
	testIncrementGrade();
	std::cout << std::endl;
	testDecrementGrade();
	std::cout << std::endl;
	return 0;
}
