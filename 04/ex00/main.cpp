/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:56:16 by etien             #+#    #+#             */
/*   Updated: 2025/03/10 18:59:13 by etien            ###   ########.fr       */
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

// Dog and Cat inherit from Animal
// Animal's makeSound function and destructor is virtual.
// makeSound function is resolved at execution time - runtime/dynamic polymorphism.

// WrongCat inherits from WrongAnimal
// Only the destructor is virtual to prevent memory leaks.
// makeSound function is resolved at compile time depending on pointer type.

// Test cases from subject
void testSubject()
{
	std::cout << GREEN << "TEST CASES: SUBJECT" << RESET << std::endl;
	const Animal* meta = new Animal();
	const Animal* i = new Dog();
	const Animal* j = new Cat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	meta->makeSound();
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	delete meta;
	delete i;
	delete j;
}

// Test cases for WrongCat class
void testWrongCat()
{
	std::cout << std::endl << GREEN << "TEST CASES: WRONGCAT" << RESET << std::endl;
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	// this WrongCat will produce the correct sound because it is used as a WrongCat
	const WrongCat* j = new WrongCat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	meta->makeSound();
	i->makeSound();
	j->makeSound();
	delete meta;
	delete i;
	delete j;
}

// Test case to demonstrate copy constructors
void testCopyConstructors()
{
	std::cout << std::endl << GREEN << "TEST CASES: COPY CONSTRUCTORS" << RESET << std::endl;
	Animal a1;
	Animal a2 = a1;
	Cat c1;
	Cat c2 = c1;
	Dog d1;
	Dog d2 = d1;
	WrongAnimal wa1;
	WrongAnimal wa2 = wa1;
	WrongCat wc1;
	WrongCat wc2 = wc1;
}

int main()
{
	testSubject();
	testWrongCat();
	testCopyConstructors();
	return 0;
}
