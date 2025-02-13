/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:04:04 by etien             #+#    #+#             */
/*   Updated: 2025/02/13 15:17:38 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>
#include <cstdlib>
#include <iomanip> // std::setw, std::right

PhoneBook::PhoneBook() : _contactCount(0), _oldestIndex(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(const Contact &newContact)
{
	if (_contactCount < 8)
	{
		_contacts[_contactCount] = newContact;
		_contactCount++;
	}
	else
	{
		_contacts[_oldestIndex] = newContact;
		// oldest index will be + 1, but % 8 to remain within the
		// bounds of the array
		_oldestIndex = (_oldestIndex + 1) % 8;
		// contactCount doesn't have to be updated because arr is already
		// at max contacts
	}
}

void PhoneBook::displayContacts() const
{
	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << "|    Index   | First Name |  Last Name |  Nickname  |" << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
}

void PhoneBook::displayContactByIndex(int index) const
{
	(void)index;
}

void addPhoneBook()
{
	std::cout << "Adding to phonebook." << std::endl;

}

void searchPhoneBook()
{
	std::cout << "Searching phonebook." << std::endl;

}

void exitPhoneBook()
{
	std::cout << "Exiting PhoneBook program." << std::endl;
	exit(0);
}
