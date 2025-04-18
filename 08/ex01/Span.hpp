/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:30:37 by etien             #+#    #+#             */
/*   Updated: 2025/04/18 15:20:09 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept> // std::overflow_error
#include <cstdlib> // std::abs
#include <algorithm> // std::sort, std::unique

class Span
{
	private:
		std::vector<int> _intVector;
		unsigned int _N;

		// OCF - prohibit default constructor
		Span();

	public:
		// OCF
		Span(const Span &src);
		Span &operator=(const Span &src);
		~Span();

		// parameterized constructor
		Span(unsigned int n);

		// getter
		const std::vector<int> &getIntVector() const;
		const unsigned int &getN() const;

		void addNumber(int number);

		// using a template function for addNumbers will allow numbers in any kind of
		// integer container to be added to the vector
		template <typename iterator>
		void addNumbers(iterator begin, iterator end)
		{
			while (begin != end)
			{
				addNumber(*begin);
				begin++;
			}
		}

		void sortVector();

		long shortestSpan();
		long longestSpan();

		class ContainerFullException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class SpanNotFoundException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
