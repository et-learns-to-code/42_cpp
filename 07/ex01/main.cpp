/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:37:26 by etien             #+#    #+#             */
/*   Updated: 2025/04/29 11:23:21 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"

int main()
{
	std::cout << GREEN << "\nTEST: INT ARRAY" << RESET << std::endl;
	int intArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	iter(intArr, sizeof(intArr) / sizeof(int), printItem);

	std::cout << GREEN << "\n\nTEST: DOUBLE ARRAY" << RESET << std::endl;
	double doubleArr[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
	iter(doubleArr, sizeof(doubleArr) / sizeof(double), printItem);

	std::cout << GREEN << "\n\nTEST: CHAR ARRAY" << RESET << std::endl;
	char charArr[] =  {'a', 'b', 'c', 'd', 'e'};
	iter(charArr, sizeof(charArr) / sizeof(char), printItem);

	std::cout << GREEN << "\n\nTEST: STRING OBJECT ARRAY" << RESET << std::endl;
	std::string stringArr[] = {"this", "is", "a", "string", "object", "array"};
	iter(stringArr, sizeof(stringArr) / sizeof(std::string), printItem);
	std::cout << "\n" << std::endl;

	return 0;
}
