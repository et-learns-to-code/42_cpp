/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:21 by etien             #+#    #+#             */
/*   Updated: 2025/02/14 17:49:29 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// int isalpha(int c);
// int toupper(int c);
// std::toupper returns an int, so it needs to be cast back to char when printing.
void print_arg(char *arg)
{
	while (*arg)
	{
		if (std::isalpha(*arg))
			std::cout << (char) std::toupper(*arg);
		else
			std::cout << *arg;
		arg++;
	}
}

int main(int ac, char **av)
{
	av++;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (*av)
		{
			print_arg(*av);
			av++;
		}
		std::cout << std::endl;
	}
	return (0);
}
