#include "Contact.hpp"

bool setFirstName()
{
	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);
	if (!isValidName(firstName))
	{
		std::cout << "Field cannot be empty.\n"
		return (false);
	}
	return (true);
}

bool setLastName()
{
	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	if (!isValidName(lastName))
	{
		std::cout << "Field cannot be empty.\n"
		return (false);
	}
	return (true);
}

bool setNickname()
{
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	if (nickname.empty())
	{
		std::cout << "Field cannot be empty.\n"
		return (false);
	}
	return (true);
}

bool setPhoneNumber()
{
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	if (phoneNumber.empty())
	{
		std::cout << "Field cannot be empty.\n"
		return (false);
	}
	return (true);
}

bool setDarkestSecret()
{
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);
	if (darkestSecret.empty())
	{
		std::cout << "Field cannot be empty.\n"
		return (false);
	}
	return (true);
}

void addContact()
{
	while (!setFirstName());
	while (!setLastName());
	while (!setNickname());
	while (!setPhoneNumber());
	while (!setDarkestSecret());

	std::cout << "Contact successfully added.\n"
}
