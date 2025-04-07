/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:44:56 by etien             #+#    #+#             */
/*   Updated: 2025/04/07 19:35:17 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// default constructor
Serializer::Serializer()
{
	// std::cout << "Serializer object default constructor called." << std::endl;
}

// copy constructor
Serializer::Serializer(const Serializer &src)
{
	// std::cout << "Serializer object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
Serializer &Serializer::operator=(const Serializer &src)
{
	// std::cout << "Serializer object copy assignment operator called." << std::endl;
	(void) src;
	return *this;
}

// destructor
Serializer::~Serializer()
{
	// std::cout << "Serializer object destructor called." << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

