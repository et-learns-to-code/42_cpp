/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:54:41 by etien             #+#    #+#             */
/*   Updated: 2025/04/22 15:24:16 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./btc <input file>" << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange bitcoinExchange;
		bitcoinExchange.evaluate(std::string(av[1]));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
