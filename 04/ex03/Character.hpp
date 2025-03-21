/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:45:15 by etien             #+#    #+#             */
/*   Updated: 2025/03/11 11:39:02 by etien            ###   ########.fr       */
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
		// The const variable cannot be left un-initialized at the time of the declaration.
		static const int _inventorySize = 4;
		std::string _name;
		AMateria *_inventory[_inventorySize];

	public:
		// OCF
		Character();
		Character(const Character &src);
		Character &operator=(const Character &src);
		~Character();

		// custom constructor
		Character(std::string name);

		// override of pure virtual functions in base class
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
