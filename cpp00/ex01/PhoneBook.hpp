#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

// const in function declaration ensures the function does not modify any member variables of the class when it is called.
class PhoneBook
{
	private:
		Contact contacts[8];
		int totalContacts;
		int currentIndex;

	public:
		PhoneBook();
		void addContact();
		void searchContacts() const;
		void displayContacts() const;
		void displayContact(int index);
};

#endif
