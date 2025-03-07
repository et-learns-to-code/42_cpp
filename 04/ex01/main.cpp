/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:56:16 by etien             #+#    #+#             */
/*   Updated: 2025/03/07 17:07:35 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

#define GREEN "\033[32m"
#define RESET "\033[0m"

// Dog and Cat classes now have a Brain object containing ideas[100].
// Update the Dog and Cat classes to correctly construct and destroy the brains.
// Take note to make deep copies of both the ideas and Brain objects.
// Deep copies means independent memory allocations where the values are
// copied to a separate memory location rather than two objects sharing
// pointers to the same memory.

int main()
{
	// Test cases from subject
	{
		std::cout << GREEN << "TEST CASES: SUBJECT" << RESET << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	return 0;
}
