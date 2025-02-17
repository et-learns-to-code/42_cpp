/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:36:04 by etien             #+#    #+#             */
/*   Updated: 2025/02/17 15:22:55 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	// Internal data members
	private:
		Contact _contacts[8];
		int _contactCount;
		int _oldestIndex;

	// Constructor, destructor and public methods
	public:
		PhoneBook();
		~PhoneBook();

		void addToPhoneBook();
		void searchPhoneBook() const;

	// Internal helper functions
	private:
		void addContact(const Contact &newContact);
		void displayContacts() const;
		void displayContactByIndex(int index) const;
};

#endif
