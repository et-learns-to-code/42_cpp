/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:37:26 by etien             #+#    #+#             */
/*   Updated: 2025/04/09 13:46:56 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"

int main()
{
	std::cout << std::endl;

	std::cout << GREEN << "TEST: INT ARRAY" << RESET << std::endl;
	int int_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	iter(int_arr, sizeof(int_arr) / sizeof(int), printItem);
	std::cout << std::endl << std::endl;

	std::cout << GREEN << "TEST: DOUBLE ARRAY" << RESET << std::endl;
	double double_arr[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
	iter(double_arr, sizeof(double_arr) / sizeof(double), printItem);
	std::cout << std::endl << std::endl;

	std::cout << GREEN << "TEST: CHAR ARRAY" << RESET << std::endl;
	char char_arr[] =  {'a', 'b', 'c', 'd', 'e'};
	iter(char_arr, sizeof(char_arr) / sizeof(char), printItem);
	std::cout << std::endl << std::endl;

	std::cout << GREEN << "TEST: STRING OBJECT ARRAY" << RESET << std::endl;
	std::string string_arr[] = {"this", "is", "a", "string", "object", "array"};
	iter(string_arr, sizeof(string_arr) / sizeof(std::string), printItem);
	std::cout << std::endl << std::endl;

	return 0;
}
