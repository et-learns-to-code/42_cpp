#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		Contact();
		bool setFirstName();
		bool setLastName();
		bool setNickname();
		bool setPhoneNumber();
		bool setDarkestSecret();
};

#endif
