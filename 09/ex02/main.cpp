/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:54:41 by etien             #+#    #+#             */
/*   Updated: 2025/04/25 17:15:05 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

// Significance of Jacobsthal sequence:
// The Jacobsthal-based index sequence is used in the Ford-Johnson algorithm to determine 
// the optimal order for inserting the smaller elements from pairs into the final sorted array. 
// By doing so, it minimizes the number of comparisons needed during binary search insertions.
// - Binary insertion depends on the number of elements already in the list (search window size).
// - If you insert elements too early, the window is too small → inefficient.
// - If you insert elements too late, you've missed opportunities for earlier placement.
// - The Jacobsthal pattern cleverly balances the depth and width of search windows to avoid worst-case comparisons.
// By processing insertions in reversed Jacobsthal order, each new insertion lands in a search space of 
// ideal size — large enough to narrow quickly, but not so large that it's too costly.

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
