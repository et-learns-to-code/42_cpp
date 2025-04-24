/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:54:41 by etien             #+#    #+#             */
/*   Updated: 2025/04/24 17:13:55 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

// Your program must:
// - be able to use a positive integer sequence as argument.
// - use the merge-insert sort algorithm (Ford-Johnson) to sort
//   the positive integer sequence.
// - be able to handle at least 3000 different integers.
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
		pmergeMe.compare(av);
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << e.what() << RESET << std::endl;
	}
	return 0;
}
