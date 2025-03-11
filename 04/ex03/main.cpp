/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:16:22 by etien             #+#    #+#             */
/*   Updated: 2025/03/11 17:01:20 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

// abstract class - AMateria
// concrete classes - Character, Cure, Ice, MateriaSource
// interface - ICharacter, IMateriaSource
// ^ (all functions = 0)

// Base class		  Derived class
// AMateria			- Cure, Ice
// ICharacter		- Character
// IMateriaSource 	- MateriaSource

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// modified the subject test case:
// src->learnMateria(new Ice());
// src->learnMateria(new Cure());
// will create inaccessible new instances of Ice and Cure that will cause leaks
// because they can't be deleted.
void testSubject()
{
	std::cout << GREEN << "TEST: SUBJECT" << RESET << std::endl;

	IMateriaSource* src = new MateriaSource();

	AMateria *ice = new Ice();
	AMateria *cure = new Cure();

	src->learnMateria(ice);
	src->learnMateria(cure);

	delete ice;
	delete cure;

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void myTest()
{
	std::cout << std::endl << GREEN << "TEST: COMPREHENSIVE" << RESET << std::endl;

	AMateria *materia1 = new Cure();
	AMateria *materia2 = new Ice();
	AMateria *materia3 = materia1->clone();
	AMateria *materia4 = materia2->clone();
	AMateria *materia5 = materia3->clone();

	std::cout << "materia1 type: " << materia1->getType() << std::endl;
	std::cout << "materia2 type: " << materia2->getType() << std::endl;
	std::cout << "materia3 type: " << materia3->getType() << std::endl;
	std::cout << "materia4 type: " << materia4->getType() << std::endl;
	std::cout << "materia5 type: " << materia5->getType() << std::endl;
	std::cout << std::endl;

	ICharacter *character1 = new Character("Cloud");
	ICharacter *character2 = new Character("Zack");
	std::cout << std::endl;

	materia1->use(*character1);
	materia2->use(*character2);



	// character1->equip()




	delete materia1;
	delete materia2;
	delete materia3;
	delete materia4;
	delete materia5;

	delete character1;
	delete character2;


}


int main()
{
	testSubject();
	myTest();
	return 0;
}

// Should output:
// $> clang++ -W -Wall -Werror *.cpp
// $> ./a.out | cat -e
// * shoots an ice bolt at bob *$
// * heals bob's wounds *$
