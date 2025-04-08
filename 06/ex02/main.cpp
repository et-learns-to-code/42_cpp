/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:28:42 by etien             #+#    #+#             */
/*   Updated: 2025/04/08 14:42:11 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib> // srand()
#include <ctime> // time()

#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

// Randomly instantiates A, B or C and returns the instance as a Base pointer.
Base * generate(void)
{
	int i = rand() % 3;

	switch (i)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			std::cout << "Failed to generate random instance." << std::endl;
			return NULL;
	}
}

// Prints the actual type of the object pointed to by p: "A", "B" or "C".
// Derived* ptr = dynamic_cast<Derived*>(basePtr);
// If casting succeeds, the pointer will be non-null;
// If casting fails, a nullptr is returned.
void identify(Base* p)
{
	std::string print = "Pointer p points to an instance of ";

	if (dynamic_cast<A*>(p))
		std::cout << print << "A." << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << print << "B." << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << print << "C." << std::endl;
	else
		std::cout << "Unidentified instance." << std::endl;
}

// Prints the actual type of the object pointed to by p: "A", "B" or "C".
// This function works with a reference instead of a pointer.
// Derived& ref = dynamic_cast<Derived&>(baseRef);
// If casting fails, an exception will be thrown, so the function
// should be called within a try-catch wrapper.
void identify(Base& p)
{
	std::string print = "Reference p points to an instance of ";

	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << print << "A." << std::endl;
		return;
	}
	// ellipsis (...) used as the parameter of catch will catch any exception
	// no matter what the type of the exception thrown.
	catch(...) {}

	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << print << "B." << std::endl;
		return;
	}
	catch(...) {}

	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << print << "C." << std::endl;
		return;
	}
	catch(...) {}

	std::cout << "Unidentified instance." << std::endl;
}

int main()
{
	srand(time(NULL));

	Base* p = NULL;

	std::cout << std::endl << GREEN
				<< "GENERATING 10 RANDOM INSTANCES OF A/B/C."
				<< RESET << std::endl << std::endl;

	for (int i = 0; i < 10; i++)
	{
		std::cout << BLUE << "Trial " << i + 1 << ":" << RESET << std::endl;
		p = generate();
		identify(p);
		identify(*p);
		std::cout << std::endl;
		delete p;
	}
	return 0;
}
