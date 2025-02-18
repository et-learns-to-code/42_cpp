/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:26:19 by etien             #+#    #+#             */
/*   Updated: 2025/02/18 18:00:48 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

// HumanB starts out weaponless, so a pointer is more appropriate
// because a reference must always be valid after initialization,
// and you can’t reassign a reference, but a pointer can be null.
// A pointer lets HumanB start without a weapon and later assign or
// change its weapon dynamically.
class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon;

	public:
		HumanB(std::string name);
		~HumanB();

		void attack();
		// Any changes made to weapon in the setWeapon function will
		// persist outside the scope of the function because the
		// original object (not a copy) is being modified.
		void setWeapon(Weapon &weapon);
};

#endif
