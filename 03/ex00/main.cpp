/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:30:02 by etien             #+#    #+#             */
/*   Updated: 2025/02/28 21:18:13 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrapDefault;
	ClapTrap clapTrapFoo = ClapTrap("Foo");
	ClapTrap clapTrap(clapTrapFoo);

	clapTrap.printStatus();
	clapTrap.attack("enemy");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(3);
	clapTrap.beRepaired(2);
	clapTrap.beRepaired(1);
	for (int i = 0; i < 8; i++)
		clapTrap.attack("enemy");
	clapTrap.takeDamage(3);
	clapTrap.takeDamage(7);
	clapTrap.takeDamage(1);
	clapTrap.attack("enemy");
	clapTrap.beRepaired(10);
	return 0;
}
