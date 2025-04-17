/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:54:41 by etien             #+#    #+#             */
/*   Updated: 2025/04/17 19:02:45 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>
#include <list>
#include <sstream>

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
	// ostringstream objects store a string buffer.
	std::ostringstream mutantStackBuffer;
	std::ostringstream listBuffer;
	// saving the original cout buffer so we can restore it later.
	// rdbuf() has two forms:
	// 1) getter that will return a pointer to a streambuf object
	// 2) setter that sets the inputted streambuf to be the buffer associated
	//    with the stream it is called on.
	//    In this form, it works like dup() in C.
	std::streambuf *originalBuffer = std::cout.rdbuf();

	// redirecting cout to write to mutantStackBuffer
	std::cout.rdbuf(mutantStackBuffer.rdbuf());
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

	// redirecting cout to write to mutantStackBuffer
	std::cout.rdbuf(listBuffer.rdbuf());
	std::cout << YELLOW << "\nTEST: SUBJECT (LIST)" << RESET << std::endl;

	std::list<int> list;

	// push_back() - add element at the end.
	list.push_back(5);
	list.push_back(17);

	// top() - access next element.
	std::cout << list.top() << std::endl;

	// pop_back() - delete last element.
	list.pop_back();

	std::cout << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	//[...]
	list.push_back(0);

	MutantStack<int>::iterator it = list.begin();
	MutantStack<int>::iterator ite = list.end();

	++it;
	--it;
	while (it != ite)
	{
		// print out stack contents
		// 5, 3, 5, 737, 0
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> l(list);

	std::cout << YELLOW << "\nRESULT OF COMPARISON: " << RESET << std::endl;

	std::cout.rdbuf(originalBuffer);

	std::cout << "mutantStack output: " << mutantStackBuffer.str() << std::endl;
	std::cout << "List output: " << listBuffer.str() << std::endl;

	if (mutantStackBuffer.str() == listBuffer.str())
		std::cout << GREEN << "Output from mutantStack and list are identical." << RESET << std::endl;
	else
		std::cout << RED << "Output from mutantStack and list differ." << RESET << std::endl;
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
