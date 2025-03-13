/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:16:22 by etien             #+#    #+#             */
/*   Updated: 2025/03/13 14:20:28 by etien            ###   ########.fr       */
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
	std::cout << std::endl << GREEN << "TEST: SUBJECT" << RESET << std::endl << std::endl;

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

void testComprehensive()
{
	std::cout << std::endl << GREEN << "TEST: COMPREHENSIVE" << RESET << std::endl;

	AMateria *materia1 = new Cure();
	AMateria *materia2 = new Ice();
	AMateria *materia3 = materia1->clone();
	AMateria *materia4 = materia2->clone();
	AMateria *materia5 = materia3->clone();

	std::cout << std::endl << RED << "AMateria - clone & getType" << RESET << std::endl;
	std::cout << "materia1 type: " << materia1->getType() << std::endl;
	std::cout << "materia2 type: " << materia2->getType() << std::endl;
	std::cout << "materia3 type: " << materia3->getType() << std::endl;
	std::cout << "materia4 type: " << materia4->getType() << std::endl;
	std::cout << "materia5 type: " << materia5->getType() << std::endl;

	ICharacter *character1 = new Character("Cloud");
	ICharacter *character2 = new Character("Zack");

	std::cout << std::endl << RED << "AMateria - use" << RESET << std::endl;
	materia1->use(*character1);
	materia2->use(*character2);

	std::cout << std::endl << RED << "Character - getName" << RESET << std::endl;
	std::cout << "character1 name: " << character1->getName() << std::endl;
	std::cout << "character2 name: " << character2->getName() << std::endl;

	std::cout << std::endl << RED << "Character - equip" << RESET << std::endl;
	// null check
	character1->equip(NULL);
	// equipping character1
	character1->equip(materia1);
	character1->equip(materia2);
	character1->equip(materia3);
	character1->equip(materia4);
	// equipping to full inventory
	character1->equip(materia5);
	// re-equipping materia1
	character1->equip(materia1);
	// equipping character2
	character2->equip(materia5);

	std::cout << std::endl << RED << "Character - use" << RESET << std::endl;
	// use Materia at invalid index
	character1->use(4, *character2);
	// use Materia at empty slot
	character2->use(1, *character1);
	// use Materia on target
	character1->use(0, *character2);
	character1->use(1, *character2);

	std::cout << std::endl << RED << "Character - unequip" << RESET << std::endl;
	// unequip at invalid index
	character1->unequip(4);
	// unequip empty slot
	character2->unequip(1);
	// unequip materia5 from character2
	character2->unequip(0);

	IMateriaSource* src = new MateriaSource();

	std::cout << std::endl << RED << "MateriaSource - learnMateria" << RESET << std::endl;
	src->learnMateria(materia1);
	src->learnMateria(materia2);
	src->learnMateria(materia3);
	src->learnMateria(materia4);
	// learning Materia when templates is full
	src->learnMateria(materia5);

	std::cout << std::endl << RED << "MateriaSource - createMateria" << RESET << std::endl;
	AMateria *materiaSrc1 = src->createMateria("cure");
	AMateria *materiaSrc2 = src->createMateria("ice");
	// Materia not in templates - no new instance will be created
	AMateria *materiaSrc3 = src->createMateria("fire");

	// Materia in character inventory slots will be deleted by the character destructor
	// Unequipped Materia must be deleted manually
	delete materia5;

	delete character1;
	delete character2;

	delete src;

	delete materiaSrc1;
	delete materiaSrc2;
	delete materiaSrc3;
}

int main()
{
	testSubject();
	testComprehensive();
	return 0;
}

// Should output:
// $> clang++ -W -Wall -Werror *.cpp
// $> ./a.out | cat -e
// * shoots an ice bolt at bob *$
// * heals bob's wounds *$
