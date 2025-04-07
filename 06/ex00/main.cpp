/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:44:54 by etien             #+#    #+#             */
/*   Updated: 2025/04/07 13:46:46 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <string>
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Incorrect number of arguments." << std::endl;
		return 1;
	}
	ScalarConverter::convert(std::string(av[1]));
	return 0;
}
