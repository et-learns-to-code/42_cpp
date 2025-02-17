/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:36:04 by etien             #+#    #+#             */
/*   Updated: 2025/02/14 14:55:12 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contacts[8];
		int _contactCount;
		int _oldestIndex;

	public:
		PhoneBook();
		~PhoneBook();

		void addContact(const Contact &newContact);
		void displayContacts() const;
		void displayContactByIndex(int index) const;
		void addToPhoneBook();
		void searchPhoneBook() const;
};

#endif
