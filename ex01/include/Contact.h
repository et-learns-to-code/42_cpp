#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
	enum		FieldIndex { FIRST_NAME, LAST_NAME, NICKNAME, PHONE_NUMBER, DARKEST_SECRET };
	std::string	fields[5];
};

#endif
