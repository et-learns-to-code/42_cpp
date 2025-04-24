/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:54:41 by etien             #+#    #+#             */
/*   Updated: 2025/04/24 16:59:07 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>

#define YELLOW "\033[33m"
#define RESET "\033[0m"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << YELLOW << "Error: could not open file." << RESET << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange bitcoinExchange;
		bitcoinExchange.evaluate(std::string(av[1]));
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << e.what() << RESET << std::endl;
	}
	return 0;
}
