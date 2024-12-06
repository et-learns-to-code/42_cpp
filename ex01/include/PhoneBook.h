#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "../include/main.h"
# include "../include/Contact.h"

# define MAX_CONTACTS 8

class PhoneBook
{
	public:
		Contact	contacts[MAX_CONTACTS];
		int		current_index;
		PhoneBook();
		~PhoneBook();

};

#endif
