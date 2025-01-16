#include "PhoneBook.hpp"
#include <iostream>

// ":"  The initialization list is used to initialize the data members of the class before the constructor's body executes. currentIndex(0) means the currentIndex member is initialized with the value 0 when an object of type PhoneBook is created. More efficient variable assignment than assigning in constructor body.
PhoneBook::PhoneBook() : currentIndex(0)
{

}

void PhoneBook::addContact()
{
	std::string first, last, nick, phone, secret;

	std::cout << "Enter first name: ";
	std::getline(std::cin, first);
	std::cout << "Enter last name: ";
	std::getline(std::cin, last);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nick);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phone);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, secret);

	if (first.empty() || last.empty() || nick.empty()
	|| phone.empty() || secret.empty())
	{
		std::
	}

}



