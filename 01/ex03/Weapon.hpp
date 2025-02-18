/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:24:23 by etien             #+#    #+#             */
/*   Updated: 2025/02/18 17:21:43 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string _type;

	public:
		Weapon(std::string type);
		~Weapon();

		// Returns a reference to a std::string (not a copy).
		// The const ensures that the caller cannot modify the returned string
		// which would break encapsulation.
		const std::string& getType();
		void setType(std::string type);
};

#endif
