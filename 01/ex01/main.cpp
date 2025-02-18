/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:58:38 by etien             #+#    #+#             */
/*   Updated: 2025/02/18 11:55:29 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

// call delete[] to free the array.
int main()
{
	int N = 10;

	Zombie *horde = zombieHorde(N, "Zombie");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
}
