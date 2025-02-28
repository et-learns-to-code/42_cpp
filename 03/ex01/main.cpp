/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:30:02 by etien             #+#    #+#             */
/*   Updated: 2025/02/28 21:19:29 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap scavTrapDefault;
	ScavTrap scavTrapFoo = ScavTrap("Foo");
	ScavTrap scavTrap(scavTrapFoo);

	scavTrap.printStatus();
	scavTrap.attack("enemy");
	scavTrap.takeDamage(5);
	scavTrap.beRepaired(3);
	scavTrap.beRepaired(2);
	scavTrap.beRepaired(1);
	for (int i = 0; i < 8; i++)
		scavTrap.attack("enemy");
	scavTrap.takeDamage(3);
	scavTrap.takeDamage(7);
	scavTrap.takeDamage(1);
	scavTrap.attack("enemy");
	scavTrap.beRepaired(10);
	scavTrap.guardGate();
	return 0;
}
