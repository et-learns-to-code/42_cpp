/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:47:29 by etien             #+#    #+#             */
/*   Updated: 2025/02/20 11:29:15 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout
	<< "DEBUG: "
	<< std::endl
	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup"
		"burger. I really do!"
	<< std::endl;
}

void Harl::info( void )
{
	std::cout
	<< "INFO: "
	<< std::endl
	<< "I cannot believe adding extra bacon costs more money. You didn't put"
		"enough bacon in my burger! If you did, I wouldn't be asking for more!"
	<< std::endl;
}

void Harl::warning( void )
{
	std::cout
	<< "WARNING: "
	<< std::endl
	<< "I think I deserve to have some extra bacon for free. I've been coming for"
		"years whereas you started working here since last month."
	<< std::endl;
}

void Harl::error( void )
{
	std::cout
	<< "ERROR: "
	<< std::endl
	<< "This is unacceptable! I want to speak to the manager now."
	<< std::endl;
}

Harl::Harl()
{
	std::cout << "Harl was created." << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl was destroyed." << std::endl;
}

void Harl::complain( std::string level )
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	// An array of pointers to member functions of the Harl class that
	// return void and take no arguments.
	void (Harl::*complain_ptr[])(void) =
	// addresses of the member functions
	{&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
		if (level == levels[i])
		{
			// 1) this is a pointer to the current object (an instance of Harl).
			// 2) this->*complain_ptr[i] dereferences the function pointer for
			//    the current instance of the class (because the pointer is tied
			//    to non-static member functions).
			// 3) () invokes the function.
			// A member function pointer isn’t like a normal function pointer;
			// it doesn’t point to a global address but an offset within an
			// object’s memory layout.
			// complain_ptr[i]() would only work for static member functions
			// (which aren’t tied to a particular instance).
			(this->*complain_ptr[i])();
			break;
		}
}
