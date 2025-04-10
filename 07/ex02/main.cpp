/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:54:41 by etien             #+#    #+#             */
/*   Updated: 2025/04/10 14:29:12 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
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

int main()
{


	// Array<int> intArray(5);
	// intArray[0] = 42;
	// std::cout << intArray[0] << std::endl;
	// std::cout << intArray[1] << std::endl;


	// try
	// {
	// 	intArray[52];

	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
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
