#include "phonebook.hpp"


// std::string::find_first_not_of():
// - Searches the string for the first character that does not match any
// of the characters specified in its arguments.

// std::string::find_last_not_of():
// - Searches the string for the last character that does not match any of
// the characters specified in its arguments.

// Both functions return the position of the first character that does not match.
// If no such characters are found, the function returns string::npos.

// std::string::substr
// The substring is the portion of the object that starts at character position pos
// and spans len characters (or until the end of the string, whichever comes first).


std::string trim(const std::string &str)
{
	size_t first = str.find_first_not_of(" \t");
	size_t last = str.find_last_not_of(" \t");

	if (first == std::string::npos || last == std::string::npos)
		return ("");
	return str.substr(first, last - first + 1);
}

bool isValidName(const std::string &name)
{

}
