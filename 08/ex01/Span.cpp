/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:30:46 by etien             #+#    #+#             */
/*   Updated: 2025/04/15 18:54:19 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// default constructor
Span::Span()
{
	// std::cout << "Span object default constructor called." << std::endl;
}

// copy constructor
Span::Span(const Span &src)
{
	// std::cout << "Span object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
Span &Span::operator=(const Span &src)
{
	// std::cout << "Span object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
		// this->_grade = src.getGrade();
	return *this;
}

// destructor
Span::~Span()
{
	// std::cout << "Span object destructor called." << std::endl;
}
