/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:54:41 by etien             #+#    #+#             */
/*   Updated: 2025/04/10 15:46:11 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

// test with leaks
int main()
{
	{
		std::cout << GREEN << "\nTEST: DEFAULT CONSTRUCTOR (INT)" << RESET << std::endl;
		Array<int> emptyArray;
		std::cout << "Size of emptyArray: " << emptyArray.size() << std::endl;
		try
		{
			std::cout << "emptyArray[0]: " << emptyArray[0] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << GREEN << "\nTEST: PARAMETERIZED CONSTRUCTOR (INT)" << RESET << std::endl;
		Array<int> nArray(3);
		std::cout << "Size of nArray: " << nArray.size() << std::endl;
		try
		{
			std::cout << "nArray[0]: " << nArray[0] << std::endl;
			std::cout << "nArray[1]: " << nArray[1] << std::endl;
			std::cout << "nArray[2]: " << nArray[2] << std::endl;
			std::cout << "nArray[3]: " << nArray[3] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << GREEN << "\nTEST: COPY CONSTRUCTOR (INT)" << RESET << std::endl;
		Array<int> originalArray(5);
		std::cout << "Size of originalArray: " << originalArray.size() << std::endl;
		originalArray[0] = 1;
		originalArray[1] = 2;
		originalArray[2] = 3;
		originalArray[3] = 4;
		originalArray[4] = 5;
		Array<int> copyArray(originalArray);
		std::cout << "Size of copyArray: " << copyArray.size() << std::endl;
		std::cout << "originalArray[0]: " << originalArray[0]
					<< "; copyArray[0]: " << copyArray[0] << std::endl
					<< "originalArray[1]: " << originalArray[1]
					<< "; copyArray[1]: " << copyArray[1] << std::endl
					<< "originalArray[2]: " << originalArray[2]
					<< "; copyArray[2]: " << copyArray[2] << std::endl
					<< "originalArray[3]: " << originalArray[3]
					<< "; copyArray[3]: " << copyArray[3] << std::endl
					<< "originalArray[4]: " << originalArray[4]
					<< "; copyArray[4]: " << copyArray[4] << std::endl;
		std::cout << GREEN << "\nTEST: DEEP COPY (INT)" << RESET << std::endl;
		copyArray[0] = 10;
		copyArray[1] = 20;
		copyArray[2] = 30;
		copyArray[3] = 40;
		copyArray[4] = 50;
		std::cout << "originalArray[0]: " << originalArray[0]
					<< "; copyArray[0]: " << copyArray[0] << std::endl
					<< "originalArray[1]: " << originalArray[1]
					<< "; copyArray[1]: " << copyArray[1] << std::endl
					<< "originalArray[2]: " << originalArray[2]
					<< "; copyArray[2]: " << copyArray[2] << std::endl
					<< "originalArray[3]: " << originalArray[3]
					<< "; copyArray[3]: " << copyArray[3] << std::endl
					<< "originalArray[4]: " << originalArray[4]
					<< "; copyArray[4]: " << copyArray[4] << std::endl;
	}
		{
		std::cout << GREEN << "\nTEST: ASSIGNMENT OPERATOR (STRING)" << RESET << std::endl;
		Array<std::string> originalArray(5);
		std::cout << "Size of originalArray: " << originalArray.size() << std::endl;
		originalArray[0] = "This";
		originalArray[1] = "is";
		originalArray[2] = "the";
		originalArray[3] = "original";
		originalArray[4] = "message.";
		Array<std::string> copyArray = originalArray;
		std::cout << "Size of copyArray: " << copyArray.size() << std::endl;
		std::cout << "originalArray[0]: " << originalArray[0]
					<< "; copyArray[0]: " << copyArray[0] << std::endl
					<< "originalArray[1]: " << originalArray[1]
					<< "; copyArray[1]: " << copyArray[1] << std::endl
					<< "originalArray[2]: " << originalArray[2]
					<< "; copyArray[2]: " << copyArray[2] << std::endl
					<< "originalArray[3]: " << originalArray[3]
					<< "; copyArray[3]: " << copyArray[3] << std::endl
					<< "originalArray[4]: " << originalArray[4]
					<< "; copyArray[4]: " << copyArray[4] << std::endl;
		std::cout << GREEN << "\nTEST: DEEP COPY (STRING)" << RESET << std::endl;
		copyArray[0] = "The";
		copyArray[1] = "message";
		copyArray[2] = "has";
		copyArray[3] = "been";
		copyArray[4] = "changed.";
		std::cout << "originalArray[0]: " << originalArray[0]
					<< "; copyArray[0]: " << copyArray[0] << std::endl
					<< "originalArray[1]: " << originalArray[1]
					<< "; copyArray[1]: " << copyArray[1] << std::endl
					<< "originalArray[2]: " << originalArray[2]
					<< "; copyArray[2]: " << copyArray[2] << std::endl
					<< "originalArray[3]: " << originalArray[3]
					<< "; copyArray[3]: " << copyArray[3] << std::endl
					<< "originalArray[4]: " << originalArray[4]
					<< "; copyArray[4]: " << copyArray[4] << std::endl;
	}
	return 0;
}
