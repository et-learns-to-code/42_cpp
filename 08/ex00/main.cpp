/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:54:41 by etien             #+#    #+#             */
/*   Updated: 2025/04/15 16:49:52 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <iomanip>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

// test with leaks
int main()
{
	{
		std::cout << GREEN << "\nTEST: VECTOR CONTAINER" << RESET << std::endl;
	}
	{
		std::cout << GREEN << "\nTEST: LIST CONTAINER" << RESET << std::endl;
	}
	{
		std::cout << GREEN << "\nTEST: DEQUE CONTAINER" << RESET << std::endl;
	}
	return 0;
}
