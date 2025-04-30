/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:54:41 by etien             #+#    #+#             */
/*   Updated: 2025/04/30 13:16:01 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>
#include <limits>
#include <vector>
#include <list>
#include <deque>
#include <set>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void printContainerContents(Span span)
{
	std::cout << BLUE << "Container contents: ";
	const std::vector<int> vector = span.getIntVector();
	for (std::vector<int>::const_iterator it = vector.begin(); it != vector.end(); it++)
	{
		std::cout << *it;
		// --vector.end() gives you an iterator to the last element of the vector.
		if (it != --vector.end())
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
		std::cout << YELLOW << "\n- PARAMETERIZED CONSTRUCTOR" << RESET << std::endl;

		Span original = Span(3);
		std::cout << "Span original = Span(3);" << std::endl;
		std::cout << "Original container size: " << original.getN() << std::endl;
		original.addNumber(1);
		original.addNumber(2);
		original.addNumber(3);
		printContainerContents(original);

		std::cout << YELLOW << "\n- COPY CONSTRUCTOR" << RESET << std::endl;

		Span copy(original);
		std::cout << "Span copy(original);" << std::endl;
		std::cout << "Copy container size: " << copy.getN() << std::endl;
		printContainerContents(copy);
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
	{
		std::cout << YELLOW << "\nTEST: ADD MANY NUMBERS" << RESET << std::endl;

		int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

		Span sp = Span(20);
		std::cout << "Container size: " << sp.getN() << std::endl;
		printContainerContents(sp);
		std::cout << YELLOW << "\n- ADDING NUMBERS FROM VECTOR" << RESET << std::endl;
		// constructing a vector from a range
		std::vector<int> intVector(arr, arr + 5);
		sp.addNumbers(intVector.begin(), intVector.end());
		printContainerContents(sp);
		std::cout << YELLOW << "\n- ADDING NUMBERS FROM LIST" << RESET << std::endl;
		std::list<int> intList(arr + 5, arr + 10);
		sp.addNumbers(intList.begin(), intList.end());
		printContainerContents(sp);
		std::cout << YELLOW << "\n- ADDING NUMBERS FROM DEQUE" << RESET << std::endl;
		std::deque<int> intDeque(arr + 10, arr + 15);
		sp.addNumbers(intDeque.begin(), intDeque.end());
		printContainerContents(sp);
		std::cout << YELLOW << "\n- ADDING NUMBERS FROM SET" << RESET << std::endl;
		std::set<int> intSet(arr + 15, arr + 20);
		sp.addNumbers(intSet.begin(), intSet.end());
		printContainerContents(sp);
		std::cout << RED << "\nShortest span: " << sp.shortestSpan() << RESET << std::endl;
		std::cout << GREEN << "Longest span: " << sp.longestSpan() << "\n" << RESET << std::endl;
	}
	return 0;
}
