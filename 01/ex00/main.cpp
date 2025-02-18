/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:58:38 by etien             #+#    #+#             */
/*   Updated: 2025/02/18 11:03:03 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name );

void randomChump( std::string name );

// delete frees the memory allocated by new and calls the
// destructor of the object. It takes a pointer to an object,
// not the object itself.
int main()
{
	Zombie *zombie = newZombie("Rob");
	zombie->announce();
	delete zombie;
	randomChump("Bob");
}
