/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:04:04 by etien             #+#    #+#             */
/*   Updated: 2025/02/14 15:26:26 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream> // cin, cout
#include <cstdlib> // exit
#include <iomanip> // std::setw, std::right
#include <sstream> // stringstream in searchPhoneBook()

PhoneBook::PhoneBook() : _contactCount(0), _oldestIndex(0) {}

PhoneBook::~PhoneBook() {}

// This function stores a contact into the phonebook's contacts array and updates
// the contactCount and oldestIndex variables.
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

// This function displays all the contacts in the phonebook in a summarized form.
// Workflow:
// 1) Set the width of each column to 10 characters.
// setw is a non-persistent manipulator (only applies to the next output) so it should
// be called last. It will pad shorter text with space on the left (by default).
// 2) Truncate the text if it exceeds 10 characters, replacing the last
// character with a dot by calling formatText.
void PhoneBook::displayContacts() const
{
	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << "|    Index   | First Name |  Last Name |  Nickname  |" << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;

	for (int i = 0; i < _contactCount; i++)
	{
		std::cout
		<< "| "
		<< std::setw(10) << i + 1
		<< " | "
		<< std::setw(10) << formatText(_contacts[i].getFirstName())
		<< " | "
		<< std::setw(10) << formatText(_contacts[i].getLastName())
		<< " | "
		<< std::setw(10) << formatText(_contacts[i].getNickname())
		<< " |"
		<< std::endl;
	}
	std::cout << "-----------------------------------------------------" << std::endl;
}

// This function will display the full details of the contact with the specified index.
void PhoneBook::displayContactByIndex(int index) const
{
	int arr_index = index - 1;

	std::cout << std::endl << "Details for contact #" << index << ": " << std::endl;
	std::cout << std::left
		<< std::setw(16)
		<< "First name: " << this->_contacts[arr_index].getFirstName()
		<< std::endl
		<< std::setw(16)
		<< "Last name: " << this->_contacts[arr_index].getLastName()
		<< std::endl
		<< std::setw(16)
		<< "Nickname: " << this->_contacts[arr_index].getNickname()
		<< std::endl
		<< std::setw(16)
		<< "Phone number: " << this->_contacts[arr_index].getPhoneNumber()
		<< std::endl
		<< std::setw(16)
		<< "Darkest secret: " << this->_contacts[arr_index].getDarkestSecret()
		<< std::endl << std::endl;
}

// This helper function trims leading and trailing whitespaces from the input.
static std::string trim(const std::string& input)
{
	// Find the first non-whitespace character
	size_t start = input.find_first_not_of(" \t");
	// npos (no-position) means no matches
	if (start == std::string::npos)
		return ""; // If only whitespace characters, return empty string.
	 // Find the last non-whitespace character
	size_t end = input.find_last_not_of(" \t");
	return input.substr(start, end - start + 1);
}

// This function will prompt the user to fill out all contact fields.
// If the input is empty (or consists solely of whitespace), the prompt will repeat.
// The inputs are stored in an array first then mapped to the correct
// contact field in the Contact object which will be stored in the PhoneBook.
void PhoneBook::addToPhoneBook()
{
	Contact	contact;
	std::string input[5];

	const char *fieldNames[] = {"first name", "last name", "nickname",
								"phone number", "darkest secret"};

	for (int i = 0; i < 5; i++)
	{
		std::string userInput;
		while (true)
		{
			std::cout << "Enter " << fieldNames[i] << ": " << std::endl;
			if (!std::getline(std::cin, userInput))
			{
				std::cout << std::endl << "EOF detected. Exiting program." << std::endl;
				exit(0);
			}
			userInput = trim(userInput);
			if (!userInput.empty())
			{
				input[i] = userInput;
				break;
			}
			else
				std::cout << "Input is empty." << std::endl;
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

// This function will display all the saved contacts in the phonebook then prompt
// the user for the specific contact that they want to see.
// std::stringstream is used to convert the input string object to an integer.
// std::stringstream is a stream-based class in C++ that works like a buffer.
// You can "write" a string into it and then "read" it out as different
// data types, such as an integer.
// eof() in std::stringstream checks whether the input stream has reached
// the end of its buffer.
void PhoneBook::searchPhoneBook() const
{
	std::string index;
	int index_int;

	if (this->_contactCount == 0)
	{
		std::cout << std::endl << "No contacts saved yet." << std::endl << std::endl;
		return;
	}
	this->displayContacts();
	while (true)
	{
		std::cout << "Enter contact index for details: " << std::endl;
		if (!std::getline(std::cin, index))
		{
			std::cout << std::endl << "EOF detected. Exiting program." << std::endl;
			exit(0);
		}
		// index is put into the string stream
		// then extracted out into index_int
		std::stringstream ss(index);
		// !(ss >> index_int) → Checks if the extraction failed.
		// !(ss.eof()) → Checks for leftover characters.
		if (!(ss >> index_int) || !(ss.eof()))
		{
			std::cout << "Not an index." << std::endl;
			continue;
		}
		if (index_int <= 0 || index_int > this->_contactCount)
		{
			std::cout << "Index is out of range." << std::endl;
			if (index_int > this->_contactCount)
			{
				if (this->_contactCount == 1)
					std::cout << "Only 1 contact in phonebook." << std::endl;
				else
					std::cout << "Only " << this->_contactCount
							<< " contacts in phonebook." << std::endl;
			}
			continue;
		}
		else
			break;
	}
	this->displayContactByIndex(index_int);
}
