/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:04:27 by etien             #+#    #+#             */
/*   Updated: 2025/02/18 11:15:32 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// This function creates a Zombie object stored on the stack that will
// announce itself.
void randomChump( std::string name )
{
	Zombie chump = Zombie(name);
	chump.announce();
}
