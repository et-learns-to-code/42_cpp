/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:30:02 by etien             #+#    #+#             */
/*   Updated: 2025/03/01 17:33:43 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diamondTrapDefault;
	DiamondTrap diamondTrapFoo = DiamondTrap("Foo");
	DiamondTrap diamondTrap(diamondTrapFoo);

	diamondTrap.printStatus();
	diamondTrap.attack("enemy");
	diamondTrap.takeDamage(5);
	diamondTrap.beRepaired(3);
	diamondTrap.beRepaired(2);
	diamondTrap.beRepaired(1);
	for (int i = 0; i < 8; i++)
		diamondTrap.attack("enemy");
	diamondTrap.takeDamage(3);
	diamondTrap.takeDamage(7);
	diamondTrap.takeDamage(1);
	diamondTrap.attack("enemy");
	diamondTrap.beRepaired(10);
	diamondTrap.guardGate();
	diamondTrap.highFivesGuys();
	diamondTrap.whoAmI();
	diamondTrapDefault.whoAmI();
	return 0;
}
