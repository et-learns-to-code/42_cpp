/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:27:16 by etien             #+#    #+#             */
/*   Updated: 2025/03/06 14:04:59 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Learning goals of exercise:
// - File manipulation the C++ way
// - String manipulation by creating a word replacement algo

// Workflow for this task:
// 1) Open input file.
// 2) Concatenante all input file lines in a string
// 3) Replace all instances of s1 in the string
// 4) Output the string to the output file
// 5) Close both input and output files

#include <fstream>
#include <iostream>

// str.find(string, pos);
// Searches the string for the first occurrence of the sequence
// specified by its arguments.
// pos: the search only includes characters at or after position pos,
// ignoring any possible occurrences that include characters before pos.

// str.erase(pos, length);
// pos: The starting index of the substring to erase.
// length: The number of characters to remove.

// str.insert(pos, substring);
// pos: The index where the substring will be inserted.
// substring: The string to insert.

void replace_word(std::string &str, char **av)
{
	std::string s1 = av[2];
	std::string s2 = av[3];
	size_t pos = 0;

	if (s1 == "")
		return;
	while (true)
	{
		pos = str.find(s1, pos);
		if (pos == std::string::npos)
			break;
		str.erase(pos, s1.size());
		str.insert(pos, s2);
		pos += s2.size();
	}
}

int main(int ac, char **av)
{
	std::ifstream infile;
	std::ofstream outfile;
	std::string outfile_name;
	std::string line;
	std::string str;

	if (ac != 4)
	{
		std::cout << "Usage: ./replace filename s1 s2" << std::endl;
		std::cout << "Every occurence of <s1> in <filename> will be "
		"replaced by <s2> and outputted to <filename>.replace." << std::endl;
		return 1;
	}
	// use open function call instead of opening file with constructor
	// to check that file opens succesfully.
	// open() will just return void, not a file descriptor like in C.
	infile.open(av[1]);
	// is_open() → Simply checks if the file is open.
	// fail() → Checks for any failure state (e.g., file doesn’t exist, permission
	// denied, etc.). It’s generally safer to use fail() for robust error handling.
	if (infile.fail())
	{
		std::cout
		<< "Error: Could not open file " << av[1] << "."
		<< std::endl;
		return 1;
	}
	// std::getline reads a line from infile into line and returns infile —
	// a reference to the input stream.
	// The stream (infile) can be implicitly converted to a boolean value:
	//   - true if the last read operation was successful
	//     i.e., a line was successfully extracted).
	//   - false if the end of the file (EOF) is reached, or an error occurs
	//     (like a read failure).
	while (std::getline(infile, line))
	{
		str += line;
		// infile.peek() != EOF checks if there is more content in the file.
		// It returns the next character in the input sequence, without extracting it.
		if (infile.peek() != EOF)
			// getline will remove the newline character by default
			str += '\n';
	}
	infile.close();
	if (str.empty())
	{
		std::cout << "Error: Input file was empty." << std::endl;
		return 1;
	}
	replace_word(str, av);
	// std::string(av[1]) converts the C-string to a C++ std::string.
	outfile_name = std::string(av[1]) + ".replace";
	// .c_str() converts the C++ std::string to C-string
	outfile.open(outfile_name.c_str());
	if (outfile.fail())
	{
		std::cout
		<< "Error: Could not open file " << outfile_name << "."
		<< std::endl;
		return 1;
	}
	// Output the string to the outfile
	outfile << str;
	outfile.close();
}
