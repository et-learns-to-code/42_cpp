/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:27:16 by etien             #+#    #+#             */
/*   Updated: 2025/02/19 14:25:53 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Learning goals of exercise:
// - File manipulation the C++ way
// - String manipulation by creating a word replacement algo

// Workflow for this task:
// 1) Open input file.
// 2) Create output file.
// 3) Loop through each line:
// - Use std::string::find to locate s1.
// - Build a new line by appending substrings, replacing occurrences
//   of s1 with s2.
// 4) Write the modified line to the output file.
// 5) Close both files.

#include <fstream>
#include <iostream>

void replace_word(std::string str, char **av)
{
	while (true)
	{
		str.find();

	}
}


int main(int ac, char **av)
{
	std::ifstream infile;
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
	// to check that file opens succcesfully.
	infile.open(av[1]);
	// is_open() → Simply checks if the file is open.
	// fail() → Checks for any failure state (e.g., file doesn’t exist, permission
	// denied, etc.). It’s generally safer to use fail() for robust error handling.
	if (infile.fail())
	{
		std::cout << "Error: Could not open file " << av[1] << std::endl;
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
		// getline will remove the newline character by default
		str += '\n';
	}
	replace_word(str, av);




}
