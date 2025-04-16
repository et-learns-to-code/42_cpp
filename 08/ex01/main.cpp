/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:54:41 by etien             #+#    #+#             */
/*   Updated: 2025/04/16 16:29:38 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>
#include <limits>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void printContainerContents(Span span)
{
	std::cout << BLUE << "Container contents: ";
	const std::set<int> set = span.getIntSet();
	for (std::set<int>::iterator it = set.begin(); it != set.end(); it++)
	{
		std::cout << *it;
		// --set.end() gives you an iterator to the last element of the set.
		if (it != --set.end())
			std::cout << ", ";
	}
	std::cout << RESET << std::endl;
}

// Should output:
// $> ./ex01
// 2
// 14
// $>
void testSubject()
{
	std::cout << YELLOW << "\nTEST: SUBJECT" << RESET << std::endl;

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	printContainerContents(sp);

	std::cout << RED << "Shortest span: " << sp.shortestSpan() << RESET << std::endl;
	std::cout << GREEN << "Longest span: " << sp.longestSpan() << RESET << std::endl;
}

int main()
{
	testSubject();
	{
		std::cout << YELLOW << "\nTEST: CONSTRUCTORS" << RESET << std::endl;

		std::cout << YELLOW << "\nPARAMETERIZED CONSTRUCTOR" << RESET << std::endl;
		Span sp = Span(3);
		std::cout << "Span sp = Span(3);" << std::endl;
		std::cout << "Original container size: " << sp.getN() << std::endl;
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		std::cout << "Original ";
		printContainerContents(sp);

		std::cout << YELLOW << "\nCOPY CONSTRUCTOR" << RESET << std::endl;
		Span copy(sp);
		std::cout << "Span copy(sp);" << std::endl;
		std::cout << "Copy container size: " << copy.getN() << std::endl;
		std::cout << "Copy ";
		printContainerContents(sp);
	}
	{
		std::cout << YELLOW << "\nTEST: REPEATED NUMBERS (IGNORED)" << RESET << std::endl;

		Span sp = Span(2);
		std::cout << "Container size: " << sp.getN() << std::endl;
		int n1 = 42;
		int n2 = 420;
		std::cout << "Adding " << n1 << std::endl;
		sp.addNumber(n1);
		std::cout << "Adding " << n1 << std::endl;
		sp.addNumber(n1);
		std::cout << "Adding " << n2 << std::endl;
		sp.addNumber(n2);
		printContainerContents(sp);
	}
	{
		try
		{
			std::cout << YELLOW << "\nTEST: CONTAINER OVERFLOW" << RESET << std::endl;

			Span sp = Span(1);
			std::cout << "Container size: " << sp.getN() << std::endl;
			sp.addNumber(42);
			printContainerContents(sp);
			std::cout << "Adding another number." << std::endl;
			sp.addNumber(420);
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}
	{
		try
		{
			std::cout << YELLOW << "\nTEST: SPAN WITH ONE NUMBER STORED" << RESET << std::endl;

			Span sp = Span(1);
			std::cout << "Container size: " << sp.getN() << std::endl;
			sp.addNumber(42);
			printContainerContents(sp);
			std::cout << RED << "Shortest span: " << sp.shortestSpan() << RESET << std::endl;
			// std::cout << GREEN << "Longest span: " << sp.longestSpan() << RESET << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}
	{
		try
		{
			std::cout << YELLOW << "\nTEST: SPAN WITH NO NUMBERS STORED" << RESET << std::endl;

			Span sp = Span(0);
			std::cout << "Container size: " << sp.getN() << std::endl;
			printContainerContents(sp);
			// std::cout << RED << "Shortest span: " << sp.shortestSpan() << RESET << std::endl;
			std::cout << GREEN << "Longest span: " << sp.longestSpan() << RESET << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << YELLOW << "\nTEST: 10,000 NUMBERS (0-9999)" << RESET << std::endl;

		Span sp = Span(10000);
		std::cout << "Container size: " << sp.getN() << std::endl;
		for (int i = 0; i < 10000; i++)
		{
			sp.addNumber(i);
		}
		// printContainerContents(sp);
		std::cout << RED << "Shortest span: " << sp.shortestSpan() << RESET << std::endl;
		std::cout << GREEN << "Longest span: " << sp.longestSpan() << RESET << std::endl;
	}
	{
		std::cout << YELLOW << "\nTEST: INT_MIN & INT_MAX" << RESET << std::endl;

		Span sp = Span(2);
		std::cout << "Container size: " << sp.getN() << std::endl;
		sp.addNumber(std::numeric_limits<int>::max());
		sp.addNumber(std::numeric_limits<int>::min());
		printContainerContents(sp);
		std::cout << RED << "Shortest span: " << sp.shortestSpan() << RESET << std::endl;
		std::cout << GREEN << "Longest span: " << sp.longestSpan() << RESET << std::endl;
	}
	return 0;
}
