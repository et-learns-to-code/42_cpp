/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:21:22 by etien             #+#    #+#             */
/*   Updated: 2025/02/14 15:04:32 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

#include <iostream>
#include <cstdlib>

int main()
{
	PhoneBook PhoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter a command: ADD, SEARCH, EXIT" << std::endl;
		// std::getline(input_stream, string_variable, delimiter);
		// delimiter is '\n' if unspecified
		if (!std::getline(std::cin, command))
		{
			std::cout << "EOF detected. Exiting program." << std::endl;
			return (0);
		}
		// std::string overloads the == operator to compare the contents of the strings directly,
		// not just their memory addresses. So, when you do command == "ADD", it actually compares
		// the string command with the string literal "ADD", character by character.
		if (command == "ADD")
			PhoneBook.addToPhoneBook();
		else if (command == "SEARCH")
			PhoneBook.searchPhoneBook();
		else if (command == "EXIT")
		{
			std::cout << "Exiting program." << std::endl;
			return (0);
		}
		else
			std::cout << "Invalid command." << std::endl;

	}
	return (0);
}
