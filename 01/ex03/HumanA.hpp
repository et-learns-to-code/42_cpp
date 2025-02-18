/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:25:43 by etien             #+#    #+#             */
/*   Updated: 2025/02/18 17:47:07 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

// Why use a reference here (Weapon&)?
// To avoid copying a potentially expensive Weapon object.
// To ensure that _weapon always refers to a valid Weapon (as opposed to a pointer, which could be null).

// HumanA's weapon is immutable in terms of association — it’s always tied to the weapon passed at construction.
// The weapon's type can be modified, but it fundamentally refers to the same object.
class HumanA
{
	private:
		std::string _name;
		Weapon &_weapon;

	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void attack();
};

#endif
