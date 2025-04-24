/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:31:46 by etien             #+#    #+#             */
/*   Updated: 2025/04/24 17:04:34 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

class PmergeMe
{
	private:
		std::vector <int> _intVector;
		std::deque <int> _intDeque;

	public:
		// OCF
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();

		void sort(char **av);

		// exception classes are typically nested classes
		class InvalidOperandException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
