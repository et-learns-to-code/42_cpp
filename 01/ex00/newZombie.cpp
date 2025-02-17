/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:03:05 by etien             #+#    #+#             */
/*   Updated: 2025/02/17 17:28:12 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// This function allocates a Zombie on the heap (dynamic memory allocation).
// Heap allocation makes sense when you need a longer lifespan (object can
// exist beyond the scope of the function where it was created) or dynamic size.
Zombie* newZombie( std::string name )
{
	return (new Zombie(name));
}
