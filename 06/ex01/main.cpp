/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:22:30 by etien             #+#    #+#             */
/*   Updated: 2025/04/08 13:48:58 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#include <iostream>
#include <stdint.h> // uintptr_t

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

// Serialization is the process of converting a data object — a combination of code and
// data represented within a region of data storage—into a series of bytes that saves
// the state of the object in an easily transmittable form.
int main()
{
	Data data;
	data.id = 42;
	data.name = "etien";

	std::cout << GREEN << std::endl << "Before serialization:" << RESET << std::endl;
	std::cout << "id: " << data.id << std::endl;
	std::cout << "name: " << data.name << std::endl;

	std::cout << RED << std::endl << "After serialization:" << RESET << std::endl;
	uintptr_t serialized = Serializer::serialize(&data);

	std::cout << "uintptr_t: " << serialized << std::endl;

	std::cout << GREEN << std::endl << "After deserialization:" << RESET << std::endl;
	Data *deserialized = Serializer::deserialize(serialized);

	std::cout << "id: " << deserialized->id << std::endl;
	std::cout << "name: " << deserialized->name << std::endl;
	std::cout << std::endl;

	if (&data == deserialized)
		std::cout << YELLOW
					<< "Deserialization has returned a pointer to the original Data."
				 	<< RESET <<std::endl << std::endl;

	return 0;
}
