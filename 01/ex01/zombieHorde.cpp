/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:08:50 by etien             #+#    #+#             */
/*   Updated: 2025/02/18 11:56:57 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// new Zombie[N] creates N default-constructed Zombie objects on the heap.
// new[] will allocate an array of objects contiguously in memory.
// The pointer returned by new[] points to the first element of the array.
// new[] only calls the default constructor — it can’t pass arguments like the name.
// The challenge of this exercise is to modify the functions to set the names for the
// zombies because we will need to use the default constructor (without parameters).
Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return NULL;
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return horde;
}
