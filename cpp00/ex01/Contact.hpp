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
		// By using a reference (std::string&), no copy is made.
		void setContactDetails(const std::string &first, const std::string &last,
								const std::string &nick, const std::string &number,
								const std::string &secret);
};

#endif
