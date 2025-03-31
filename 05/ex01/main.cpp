/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:17:30 by etien             #+#    #+#             */
/*   Updated: 2025/03/31 15:16:35 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

void testDefaultForm()
{
	std::cout << GREEN << "TEST: DEFAULT FORM" << RESET << std::endl;
	Form form;
	std::cout << form << std::endl;
}

void testCustomCopiedForm()
{
	std::cout << GREEN << "TEST: CUSTOM AND COPIED FORM" << RESET << std::endl;
	Form original("Original", 30, 60);
	std::cout << original << std::endl;
	Form copy(original);
	std::cout << copy << std::endl;
}

void testConstructorGradeTooHigh()
{
	try
	{
		std::cout << GREEN << "TEST: FORM CONSTRUCTOR - SIGN GRADE TOO HIGH" << RESET << std::endl;
		Form alpha("Alpha", 0, 60);
		std::cout << alpha << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << GREEN << "TEST: FORM CONSTRUCTOR - EXEC GRADE TOO HIGH" << RESET << std::endl;
		Form alpha("Alpha", 30, 0);
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
		std::cout << GREEN << "TEST: FORM CONSTRUCTOR - SIGN GRADE TOO LOW" << RESET << std::endl;
		Form beta("Beta", 151, 60);
		std::cout << beta << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << GREEN << "TEST: FORM CONSTRUCTOR - EXEC GRADE TOO LOW" << RESET << std::endl;
		Form beta("Beta", 30, 151);
		std::cout << beta << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void testFormSignSucess()
{
	std::cout << GREEN << "TEST: FORM SIGN SUCCESS" << RESET << std::endl;
	Bureaucrat senior("Senior", 50);
	std::cout << senior << std::endl;
	Form form;
	std::cout << form << std::endl;
	senior.signForm(form);
	std::cout << form << std::endl;
}

void testFormSignFail()
{
	std::cout << GREEN << "TEST: FORM SIGN FAIL" << RESET << std::endl;
	Bureaucrat junior("Junior", 51);
	std::cout << junior << std::endl;
	Form form;
	std::cout << form << std::endl;
	junior.signForm(form);
	std::cout << form << std::endl;
}

int main()
{
	std::cout << std::endl;
	testDefaultForm();
	std::cout << std::endl;
	testCustomCopiedForm();
	std::cout << std::endl;
	testConstructorGradeTooHigh();
	std::cout << std::endl;
	testConstructorGradeTooLow();
	std::cout << std::endl;
	testFormSignSucess();
	std::cout << std::endl;
	testFormSignFail();
	std::cout << std::endl;
	return 0;
}
