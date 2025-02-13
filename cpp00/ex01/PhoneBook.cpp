/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:04:04 by etien             #+#    #+#             */
/*   Updated: 2025/02/13 18:37:51 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>
#include <cstdlib> // exit
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

// This function will truncate the text if it is has more than 10 characters.
// The first 9 characters will be preserved and appended with a '.'.
static std::string formatText(const std::string& text)
{
	if (text.length() > 10)
		return text.substr(0, 9) + ".";
	return text;
}

// Set the width of each column to 10 characters.
// Right-align the text within each column using std::setw and std::right.
// setw is a non-persistent manipulator (only applies to the next output)
// so it should be called last.
// Truncate the text if it exceeds 10 characters, replacing the last
// character  with a dot.
void PhoneBook::displayContacts() const
{
	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << "|    Index   | First Name |  Last Name |  Nickname  |" << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;

	for (int i = 0; i < _contactCount; i++)
	{
		std::cout
		<< "| "
		<< std::setw(10) << std::right << i
		<< " | "
		<< std::setw(10) << std::right << formatText(_contacts[i].getFirstName())
		<< " | "
		<< std::setw(10) << std::right << formatText(_contacts[i].getLastName())
		<< " | "
		<< std::setw(10) << std::right << formatText(_contacts[i].getNickname())
		<< " |"
		<< std::endl;
	}
	std::cout << "-----------------------------------------------------" << std::endl;
}

void PhoneBook::displayContactByIndex(int index) const
{
	(void)index;
}

static std::string trim(const std::string& input)
{
	// Find the first non-whitespace character
	size_t start = input.find_first_not_of(" \t");
	if (start == std::string::npos)
		return ""; // If only whitespace characters, return empty string.
	 // Find the last non-whitespace character
	size_t end = input.find_last_not_of(" \t");
	return input.substr(start, end - start + 1);
}

static bool isValidInput(const std::string& input)
{
	return !input.empty();
}

// This function will prompt the user to fill out all contact fields.
// If an input is invalid, the prompt will repeat.
// The inputs are stored in an array first then mapped to the correct
// contact field to be stored in the Contact object.
void PhoneBook::addPhoneBook()
{
	Contact	contact;
	std::string input[5];

	const char *fieldNames[] = {"first name", "last name", "nickname",
								"phone number", "darkest secret"};

	for (int i = 0; i < 5; i++)
	{
		std::string userInput;
		bool validInput = false;
		while (!validInput)
		{
			std::cout << "Enter " << fieldNames[i] << ": ";
			std::getline(std::cin, userInput);
			userInput = trim(userInput);
			if (isValidInput(userInput))
			{
				input[i] = userInput;
				validInput = true;
			}
			else
				std::cout << "Invalid input." << std::endl;
		}
	}
	contact.setFirstName(input[0]);
	contact.setLastName(input[1]);
	contact.setNickname(input[2]);
	contact.setPhoneNumber(input[3]);
	contact.setDarkestSecret(input[4]);
	this->addContact(contact);

	std::cout << std::endl << "Contact successfully added." << std::endl << std::endl;
}

void PhoneBook::searchPhoneBook()
{
	std::cout << "Searching phonebook." << std::endl;
	this->displayContacts();
}

void PhoneBook::exitPhoneBook()
{
	std::cout << "Exiting program." << std::endl;
	exit(0);
}
