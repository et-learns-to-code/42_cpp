#include "phonebook.hpp"

int	main()
{
	std::string command;
	Phonebook phonebook;

	while (true)
	{
		displayMenu();
		command = getInput();
		if (command == "ADD")
			std::cout << "Adding contact.\n";
		else if (command == "SEARCH")
			std::cout << "Searching contact.\n";
		else if (command == "EXIT")
		{
			std::cout << "Exiting program.\n";
			break;
		}
		else
			std::cout << "Invalid command.\n\n";
	}
	return (0);
}

void displayMenu()
{
	std::cout << "-----------------------------------\n";
	std::cout << " Welcome to the 80s PhoneBook App \n";
	std::cout << "-----------------------------------\n";
	std::cout << " Available commands:\n";
	std::cout << "  1. ADD    - Add a new contact\n";
	std::cout << "  2. SEARCH - Search for a contact\n";
	std::cout << "  3. EXIT   - Exit the program\n";
	std::cout << "-----------------------------------\n";
	std::cout << "Enter a command: ";
}

std::string getInput()
{
	std::string input;

	std::getline(std::cin, input);
	return (input);
}
