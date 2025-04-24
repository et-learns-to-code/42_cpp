/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:54:41 by etien             #+#    #+#             */
/*   Updated: 2025/04/24 17:03:19 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << YELLOW << "Usage: ./PmergMe <positive integer> ..." << RESET << std::endl;
		return 1;
	}
	try
	{
		av++;
		PmergeMe pmergeMe;
		pmergeMe.sort(av);
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << e.what() << RESET << std::endl;
	}
	return 0;
}
