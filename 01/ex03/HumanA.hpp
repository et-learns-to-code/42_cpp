/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:25:43 by etien             #+#    #+#             */
/*   Updated: 2025/02/18 13:54:47 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

// Why use a reference here (Weapon&)?
// To avoid copying a potentially expensive Weapon object.
// To ensure that _weapon always refers to a valid Weapon (as opposed to a pointer, which could be null).

class HumanA
{
	private:
		Weapon &_weapon;
		std::string _name;

	public:
		HumanA();
		~HumanA();

		void attack();
};

#endif
