/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:30:02 by etien             #+#    #+#             */
/*   Updated: 2025/03/01 12:06:07 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap fragTrapDefault;
	FragTrap fragTrapFoo = FragTrap("Foo");
	FragTrap fragTrap(fragTrapFoo);

	fragTrap.printStatus();
	fragTrap.attack("enemy");
	fragTrap.takeDamage(5);
	fragTrap.beRepaired(3);
	fragTrap.beRepaired(2);
	fragTrap.beRepaired(1);
	for (int i = 0; i < 8; i++)
		fragTrap.attack("enemy");
	fragTrap.takeDamage(3);
	fragTrap.takeDamage(7);
	fragTrap.takeDamage(1);
	fragTrap.attack("enemy");
	fragTrap.beRepaired(10);
	fragTrap.highFivesGuys();
	return 0;
}
