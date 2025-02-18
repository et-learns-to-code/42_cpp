/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:03:05 by etien             #+#    #+#             */
/*   Updated: 2025/02/18 10:52:22 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// This function allocates a Zombie on the heap (dynamic memory allocation).
// Heap allocation makes sense when you need a longer lifespan (object can
// exist beyond the scope of the function where it was created) or dynamic size.
// new allocates memory on the heap and calls the constructor of the object.
// It returns a pointer to the allocated object.
// The parameter to new is the constructor’s arguments (if any)
Zombie* newZombie( std::string name )
{
	return (new Zombie(name));
}
