/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:48:07 by etien             #+#    #+#             */
/*   Updated: 2025/02/20 14:30:56 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// The goal of this exercise is to learn how to use switch statements.

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./harlFilter \"level\"" << std::endl;
		return 1;
	}

	// Assign case number based on input parameter.
	int level = -1;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
		if (av[1] == levels[i])
		{
			level = i;
			break;
		}

	Harl harl;
	// Switch takes an integer (or a value that can be implicitly converted
	// to an integer, such as char or enum).
	switch (level)
	{
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl << std::endl;
	}
	return 0;
}
