/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:45:15 by etien             #+#    #+#             */
/*   Updated: 2025/03/10 18:55:33 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <iostream>
#include <string>

class Character : public ICharacter
{
	private:
		static const int _inventorySize = 4;
		AMateria *_inventory[_inventorySize];

	public:
		// OCF
		Character();
		Character(const Character &src);
		Character &operator=(const Character &src);
		~Character();

		// override of pure virtual functions in base class
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
