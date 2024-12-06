#include "../include/main.h"
#include "../include/Contact.h"
#include "../include/PhoneBook.h"

// ANSI escape sequences to clear the screen.
// \033[2J: Clears the entire screen.
// \033[H: Moves the cursor to the top-left corner.
void clear_screen()
{
	std::cout << "\033[2J\033[H";
}

void print_menu()
{
	clear_screen();
	std::cout << "Enter one of the following commands:" << std::endl;
	std::cout << "- ADD: Save a new contact" << std::endl;
	std::cout << "- SEARCH: Display a specific contact" << std::endl;
	std::cout << "- EXIT: Exit the program" << std::endl;
}

std::string get_input(std::string message)
{
	std::string input;

	std::cout << message;
	std::getline(std::cin, input);
	return (input);
}

// Due to the nature of string objects, we cannot check through the strings
// with C-style pointers, instead we have to iterate through them.
// The const_iterator is read-only and will not modify the string.
// Iterators can be dereferenced with *it.
// .start() returns an iterator to the first character of the string.
// .end() returns an iterator one past the last character of the string.
// ++it is more efficient than ++it because ++it returns the incremented
// iterator but it++ returns the current value of the iterator before
// incrementing it, which will sometimes involve the creation of a temporary
// copy of the iterator to store its original value.
// This is one of the quirks of C++ because iterators are objects but
// pointers in C are simply memory addresses.
bool valid_phone_number(std::string phone_number)
{
	for (std::string::const_iterator it = phone_number.begin();
			it != phone_number.end();
			++it)
		if (!(std::isdigit(*it) || *it == '-'))
			return (false);
	return (true);
}

void add_contact(Contact *contact)
{
	std::string phone_number;

	contact->fields[FIRST_NAME] = get_input("Enter first name: ");
	contact->fields[LAST_NAME] = get_input("Enter last name: ");
	contact->fields[NICKNAME] = get_input("Enter nickname: ");
	phone_number = get_input("Enter phone number: ");
	while (!valid_phone_number(phone_number))
	{
		std::cout << "Invalid phone number. Only digits and hyphens are allowed."
			<< std::endl;
		phone_number = get_input("Enter phone number: ");
	}
	contact->fields[PHONE_NUMBER] = phone_number;
	contact->fields[DARKEST_SECRET] = get_input("Enter darkest secret: ");
}


void print_contact(Contact *contact)
{
	std::cout << contact->fields[FIRST_NAME] << std::endl;
	std::cout << contact->fields[LAST_NAME] << std::endl;
	std::cout << contact->fields[NICKNAME] << std::endl;
	std::cout << contact->fields[PHONE_NUMBER] << std::endl;
	std::cout << contact->fields[DARKEST_SECRET] << std::endl;
}

// int main()
// {
// 	PhoneBook phonebook;
// 	add_contact(&phonebook.contacts[0]);
// 	print_contact(&phonebook.contacts[0]);
// 	return (0);
// }

int main(void)
{
	std::string command;
	PhoneBook phonebook;

	phonebook.current_index = 0;
	while (1)
	{
		print_menu();
		std::cin >> command;
		if (command == "ADD")
		{
			add_contact(&phonebook.contacts[phonebook.current_index]);
			print_contact(&phonebook.contacts[phonebook.current_index]);
		}
		else if (command == "SEARCH")
		{
			std::cout << "Display a contact" << std::endl;
		}
		else if (command == "EXIT")
		{
			std::cout << "Program will exit" << std::endl;
		}
		else
		{
			std::cout << "Error: Invalid command" << std::endl;
		}

	}
	return (0);
}



