/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:21:22 by etien             #+#    #+#             */
/*   Updated: 2025/02/13 15:40:37 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

#include <iostream>

void displayMenu()
{
	std::cout << "Enter a command: ADD, SEARCH, EXIT" << std::endl;
}

int main()
{
	PhoneBook PhoneBook;
	std::string command;
	const char *commands[] = {"ADD", "SEARCH", "EXIT"};

	// An array of function pointers corresponding to commands.
	void (PhoneBook::*actions[])(void) =
	{
		&PhoneBook::addPhoneBook,
		&PhoneBook::searchPhoneBook,
		&PhoneBook::exitPhoneBook
	};

	while (1)
	{
		displayMenu();
		// std::getline(input_stream, string_variable, delimiter);
		// delimiter is '\n' if unspecified

		std::getline(std::cin, command);
		for (int i = 0; i < 3; i++)
		{
			if (command.compare(commands[i]) == 0)
				(PhoneBook.*actions[i])();
		}
	}
	PhoneBook.displayContacts();
	return (0);
}
