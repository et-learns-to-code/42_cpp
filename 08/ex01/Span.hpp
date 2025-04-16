/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:30:37 by etien             #+#    #+#             */
/*   Updated: 2025/04/16 17:29:46 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set> // set container (containing distinct elements)
#include <stdexcept> // std::overflow_error
#include <cstdlib> // std::abs

class Span
{
	private:
		std::set<int> _intSet;
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
		const std::set<int> &getIntSet() const;
		const unsigned int &getN() const;

		void addNumber(int number);

		// using a template function for addNumbers will allow numbers in any kind of
		// integer container to be added to the set
		template <typename iterator>
		void addNumbers(iterator begin, iterator end)
		{
			while (begin != end)
			{
				addNumber(*begin);
				begin++;
			}
		}

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
