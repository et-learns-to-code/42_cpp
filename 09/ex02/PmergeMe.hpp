/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:31:46 by etien             #+#    #+#             */
/*   Updated: 2025/04/25 08:12:07 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <climits> // INT_MAX, INT_MIN
#include <algorithm> // std::find()

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

class PmergeMe
{
	private:
		std::vector <int> _intVector;
		std::deque <int> _intDeque;

		void createVector(char **av);

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
		
		class NegativeNumberException : public ParsingException
		{
			public:
				NegativeNumberException(std::string number);
		};
		
		class DuplicateNumberException : public ParsingException
		{
			public:
				DuplicateNumberException(std::string number);
		};
};

#endif
