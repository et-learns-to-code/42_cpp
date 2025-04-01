/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:42:34 by etien             #+#    #+#             */
/*   Updated: 2025/04/01 18:00:55 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>

// default constructor
// _target() will implicitly initialize _target to an empty string
ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137), _target("target")
{
	// std::cout << "ShrubberyCreationForm object default constructor called." << std::endl;
}

// copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
: AForm(src)
{
	// std::cout << "ShrubberyCreationForm object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	// std::cout << "ShrubberyCreationForm object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
		this->_target = src.getTarget();
	return *this;
}

// destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "ShrubberyCreationForm object destructor called." << std::endl;
}

// custom constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	// std::cout << "ShrubberyCreationForm object custom constructor called." << std::endl;
}

// getter
std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void ShrubberyCreationForm::beExecuted() const
{
	std::string outfile_name = this->_target + "_shrubbery";
	// .c_str() converts the C++ std::string to C-string
	// opens file with ofstream constructor
	std::ofstream outfile(outfile_name.c_str());
	if (!outfile.is_open())
	{
		std::cout
		<< "Error: Could not open file " << outfile_name << "."
		<< std::endl;
		return;
	}
	// Write ASCII trees to the outfile
	outfile
	<< "               ,@@@@@@@,\n"
	<< "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
	<< "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
	<< "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
	<< "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
	<< "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
	<< "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
	<< "       |o|        | |         | |\n"
	<< "       |.|        | |         | |\n"
	<< "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_ \n"
	<< "\n"
	<< "               (Art by jgs)\n";
	// ofstream automatically closes the file when it goes out of scope
	std::cout << "ASCII trees have been written to " << outfile_name << "." << std::endl;
}
