/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:56:16 by etien             #+#    #+#             */
/*   Updated: 2025/03/10 17:00:22 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// Test cases from subject
void testSubject()
{
	std::cout << GREEN << "TEST: SUBJECT" << RESET << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;//should not create a leak - leak will result if AAnimal destructor is not virtual
	delete i;
}

void testArray()
{
	std::cout << GREEN << "TEST: ANIMALS ARRAY" << RESET << std::endl;
	AAnimal *animals[4];
	int i = 0;
	std::cout << RED << "Creating two dogs." << RESET << std::endl;
	while (i < 2)
	{
		animals[i] = new Dog();
		animals[i]->makeSound();
		i++;
	}
	std::cout << RED << "Creating two cats." << RESET << std::endl;
	while (i < 4)
	{
		animals[i] = new Cat();
		animals[i]->makeSound();
		i++;
	}
	// deleting animals
	std::cout << RED << "Deleting two dogs and two cats." << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		delete animals[i];
}

// dog2 is a deep copy of dog1
// changing dog1's idea will not change dog2's idea, meaning that the
// ideas are deep copies stored independently in memory and proving that
// dog2 is a deep copy.
void testDogDeepCopy()
{
	std::cout << GREEN << "TEST: DOG DEEP COPY" << RESET << std::endl;
	std::cout << RED << "Creating dog1." << RESET << std::endl;
	Dog dog1;
	dog1.getBrain()->setIdea("Chase the mailman!", 0);
	std::cout << RED << "Creating dog2 as a copy of dog1." << RESET << std::endl;
	Dog dog2 = dog1;
	std::cout << "dog1 - ideas[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "dog2 - ideas[0]: " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << RED << "Changing dog1's idea." << RESET << std::endl;
	dog1.getBrain()->setIdea("Fetch! Throw it again!", 0);
	std::cout << "dog1 - ideas[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "dog2 - ideas[0]: " << dog2.getBrain()->getIdea(0) << std::endl;
}

// cat2 is a deep copy of cat1
// changing cat1's idea will not change cat2's idea, meaning that the
// ideas are deep copies stored independently in memory and proving that
// cat2 is a deep copy.
void testCatDeepCopy()
{
	std::cout << GREEN << "TEST: CAT DEEP COPY" << RESET << std::endl;
	std::cout << RED << "Creating cat1." << RESET << std::endl;
	Cat cat1;
	cat1.getBrain()->setIdea("Humans are my slaves!", 0);
	std::cout << RED << "Creating cat2 as a copy of cat1." << RESET << std::endl;
	Cat cat2 = cat1;
	std::cout << "cat1 - ideas[0]: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "cat2 - ideas[0]: " << cat2.getBrain()->getIdea(0) << std::endl;
	std::cout << RED << "Changing cat1's idea." << RESET << std::endl;
	cat1.getBrain()->setIdea("I hate the dog!", 0);
	std::cout << "cat1 - ideas[0]: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "cat2 - ideas[0]: " << cat2.getBrain()->getIdea(0) << std::endl;
}

// main function is identical to ex01.
int main()
{
	testSubject();
	testArray();
	testDogDeepCopy();
	testCatDeepCopy();
	// AAnimal animal;
	return 0;
}
