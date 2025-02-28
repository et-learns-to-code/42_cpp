/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:30:02 by etien             #+#    #+#             */
/*   Updated: 2025/02/28 15:11:02 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap;
	ClapTrap clapTrap2;

	clapTrap2 = ClapTrap("Bob");
	clapTrap = clapTrap2;
	clapTrap.printClapTrapStatus();
	clapTrap.attack("enemy");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(3);
	clapTrap.beRepaired(2);
	clapTrap.beRepaired(1);
	clapTrap.attack("enemy");
	clapTrap.attack("enemy");
	clapTrap.attack("enemy");
	clapTrap.attack("enemy");
	clapTrap.attack("enemy");
	clapTrap.attack("enemy");
	clapTrap.attack("enemy");
	clapTrap.attack("enemy");
	return 0;
}
