/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:31:46 by etien             #+#    #+#             */
/*   Updated: 2025/04/29 18:25:09 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <climits> // INT_MAX, INT_MIN
#include <algorithm> // std::find(), std::swap(), std::lower_bound()
#include <cmath> // std::pow
#include <ctime> // clock()

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class PmergeMe
{
	private:
		std::vector<int> _originalVector;
		std::vector< std::pair<int, int> > _pairVector;
		std::vector<int> _sortedVector;

		std::deque<int> _originalDeque;
		std::deque< std::pair<int, int> > _pairDeque;
		std::deque<int> _sortedDeque;

		void generateIndexSequence(int n, std::vector<int> &index);

		void sortVector(char **av);
		void createOriginalVector(char **av);
		void createPairVector(int &straggler);
		void mergeSortPairVector(int left, int right);
		void mergePairVector(int left, int mid, int right);
		void createSortedVector();
		void insertToSortedVector();

		void sortDeque(char **av);
		void createOriginalDeque(char **av);
		void createPairDeque(int &straggler);
		void mergeSortPairDeque(int left, int right);
		void mergePairDeque(int left, int mid, int right);
		void createSortedDeque();
		void insertToSortedDeque();

		// template function to checks that the container's elements are sorted in ascending order.
		template <typename it>
		bool isSorted(it first, it last)
		{
			while (first != last)
			{
				// next is reassigned from first in every loop
				it next = first;
				next++;
				if (next != last && *next < *first)
					return false;
				first++;
			}
			return true;
		}

		// template function to print out container contents
		template <typename it>
		void printContents(it first, it last)
		{
			while (first != last)
			{
				std::cout << *first << " ";
				first++;
			}
			std::cout << std::endl;
		}

		// template function to print out container contents pairs
		template <typename it>
		void printContentsPair(it first, it last)
		{
			while (first != last)
			{
				std::cout << "(" << first->first << ", " << first->second << ") ";
				first++;
			}
			std::cout << std::endl;
		}

		// template function to print out container contents (limited to first four integers)
		template <typename it>
		void printContentsTruncated(it first, it last, size_t size)
		{
			if (size <= 10)
			{
				while (first != last)
				{
					std::cout << *first << " ";
					first++;
				}
			}
			else
			{
				size_t count = 0;
				while (first != last && count < 4)
				{
					std::cout << *first << " ";
					first++;
					count++;
				}
				std::cout << "[...]";
			}
			std::cout << std::endl;
		}

	public:
		// OCF
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();

		void compare(char **av);

		// exception classes are typically nested classes
		class ParsingException : public std::exception
		{
			protected:
				std::string _message;

			public:
				ParsingException(std::string err);
				virtual ~ParsingException() throw();
				const char *what() const throw();
		};

		class InvalidNumberException : public ParsingException
		{
			public:
				InvalidNumberException(std::string number);
		};

		class IntegerOverflowException : public ParsingException
		{
			public:
				IntegerOverflowException(std::string number);
		};

		class DuplicateNumberException : public ParsingException
		{
			public:
				DuplicateNumberException(std::string number);
		};
};

#endif
