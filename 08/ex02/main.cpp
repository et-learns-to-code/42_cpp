/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:54:41 by etien             #+#    #+#             */
/*   Updated: 2025/04/17 18:04:42 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>
#include <list>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

// void printContainerContents(Span span)
// {
// 	std::cout << BLUE << "Container contents: ";
// 	const std::set<int> set = span.getIntSet();
// 	for (std::set<int>::iterator it = set.begin(); it != set.end(); it++)
// 	{
// 		std::cout << *it;
// 		// --set.end() gives you an iterator to the last element of the set.
// 		if (it != --set.end())
// 			std::cout << ", ";
// 	}
// 	std::cout << RESET << std::endl;
// }

void testSubject()
{
	{
		std::cout << YELLOW << "\nTEST: SUBJECT (MUTANTSTACK)" << RESET << std::endl;

		MutantStack<int> mstack;

		// push() - insert element to top of stack.
		mstack.push(5);
		mstack.push(17);

		// top() - access next element.
		std::cout << mstack.top() << std::endl;

		// pop() - remove top element.
		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			// print out stack contents
			// 5, 3, 5, 737, 0
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
		{
		std::cout << YELLOW << "\nTEST: SUBJECT (LIST)" << RESET << std::endl;

		MutantStack<int> mstack;

		// push() - insert element to top of stack.
		mstack.push(5);
		mstack.push(17);

		// top() - access next element.
		std::cout << mstack.top() << std::endl;

		// pop() - remove top element.
		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			// print out stack contents
			// 5, 3, 5, 737, 0
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
}

int main()
{
	testSubject();
	{
		std::cout << YELLOW << "\nTEST: CONSTRUCTORS" << RESET << std::endl;
		std::cout << YELLOW << "\n- PARAMETERIZED CONSTRUCTOR" << RESET << std::endl;
	}
	return 0;
}
