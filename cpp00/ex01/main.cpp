#include <iostream>
#include <string>

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
	std::cout << "Enter a command: \n";
}

int	main()
{
	displayMenu();
	return (0);
}
