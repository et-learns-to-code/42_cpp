/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:30:02 by etien             #+#    #+#             */
/*   Updated: 2025/02/28 17:57:02 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap scavTrapDefault;
	ScavTrap scavTrapFoo = ScavTrap("Foo");
	ScavTrap scavTrap(scavTrapFoo);

	scavTrap.printClapTrapStatus();
	scavTrap.attack("enemy");
	// scavTrap.guardGate();
	return 0;
}
