/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:54:41 by etien             #+#    #+#             */
/*   Updated: 2025/04/18 13:44:49 by etien            ###   ########.fr       */
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

	{
		// TESTING MUTANTSTACK OUTPUT

		// redirecting cout to write to mutantStackBuffer
		std::cout.rdbuf(mutantStackBuffer.rdbuf());

		MutantStack<int> mstack;

		// push() - insert element to top of the stack.
		mstack.push(5);
		mstack.push(17);

		// top() - access next element on the stack.
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

		// restore original buffer
		std::cout.rdbuf(originalBuffer);
	}
	{
		// TESTING LIST OUTPUT

		// redirecting cout to write to listBuffer
		std::cout.rdbuf(listBuffer.rdbuf());

		std::list<int> list;

		// push_back() - add element at the end.
		list.push_back(5);
		list.push_back(17);

		// back() - access the last element.
		std::cout << list.back() << std::endl;

		// pop_back() - delete last element.
		list.pop_back();

		std::cout << list.size() << std::endl;

		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		//[...]
		list.push_back(0);

		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();

		++it;
		--it;
		while (it != ite)
		{
			// print out stack contents
			// 5, 3, 5, 737, 0
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> l(list);

		// restore original buffer
		std::cout.rdbuf(originalBuffer);
	}

	std::cout << YELLOW << "\nTEST: SUBJECT - COMPARE OUTPUT (MUTANTSTACK VS LIST)\n" << RESET << std::endl;

	std::cout << "MutantStack output: \n" << mutantStackBuffer.str() << std::endl;
	std::cout << "List output: \n" << listBuffer.str() << std::endl;

	if (mutantStackBuffer.str() == listBuffer.str())
		std::cout << GREEN << "Result: Output from MutantStack and list are identical." << RESET << std::endl;
	else
		std::cout << RED << "Result: Output from MutantStack and list differ." << RESET << std::endl;
}

int main()
{
	testSubject();
	{
		std::cout << YELLOW << "\nTEST: DEFAULT CONSTRUCTOR" << RESET << std::endl;
		std::cout << "Creating mstack1 with default constructor." << std::endl;
		MutantStack<int> mstack1;
		std::cout << "Pushing numbers 1-5 to mstack1." << std::endl;
		mstack1.push(1);
		mstack1.push(2);
		mstack1.push(3);
		mstack1.push(4);
		mstack1.push(5);

		std::cout << BLUE << "\nTEST: CONST ITERATOR" << RESET << std::endl;
		std::cout << "Printing out mstack1 contents with const iterator:" << std::endl;
		MutantStack<int>::const_iterator it1 = mstack1.begin();
		MutantStack<int>::const_iterator ite1 = mstack1.end();
		while (it1 != ite1)
		{
			// will cause compiler error because const iterator cannot modify container values.
			// *it1 += 5;
			std::cout << *it1 << " ";
			it1++;
		}
		std::cout << std::endl;

		std::cout << BLUE << "\nTEST: ITERATOR" << RESET << std::endl;
		std::cout << "Incrementing all numbers in mstack1 by 5 and printing out the contents with iterator:"
					<< std::endl;
		MutantStack<int>::iterator it2 = mstack1.begin();
		MutantStack<int>::iterator ite2 = mstack1.end();
		while (it2 != ite2)
		{
			*it2 += 5;
			std::cout << *it2 << " ";
			it2++;
		}
		std::cout << std::endl;

		std::cout << YELLOW << "\nTEST: COPY CONSTRUCTOR" << RESET << std::endl;
		std::cout << "Copying mstack1 to mstack2." << std::endl;
		MutantStack<int> mstack2(mstack1);

		std::cout << BLUE << "\nTEST: CONST REVERSE ITERATOR" << RESET << std::endl;
		std::cout << "Printing out mstack2 contents with const reverse iterator:" << std::endl;
		MutantStack<int>::const_reverse_iterator it3 = mstack2.rbegin();
		MutantStack<int>::const_reverse_iterator ite3 = mstack2.rend();
		while (it3 != ite3)
		{
			// will cause compiler error because const iterator cannot modify container values.
			// *it3 -= 5;
			std::cout << *it3 << " ";
			it3++;
		}
		std::cout << std::endl;

		std::cout << YELLOW << "\nTEST: ASSIGNMENT OPERATOR" << RESET << std::endl;
		std::cout << "Assigning mstack2 to mstack3." << std::endl;
		MutantStack<int> mstack3 = mstack2;

		std::cout << BLUE << "\nTEST: REVERSE ITERATOR" << RESET << std::endl;
		std::cout << "Decrementing all numbers in mstack3 by 5 and printing out the contents with reverse iterator:"
					<< std::endl;
		MutantStack<int>::reverse_iterator it4 = mstack3.rbegin();
		MutantStack<int>::reverse_iterator ite4 = mstack3.rend();
		while (it4 != ite4)
		{
			*it4 -= 5;
			std::cout << *it4 << " ";
			it4++;
		}
		std::cout << std::endl << std::endl;
	}
	return 0;
}
