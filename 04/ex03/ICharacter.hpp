/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:35:19 by etien             #+#    #+#             */
/*   Updated: 2025/03/11 15:27:56 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

// forward declaraction to prevent circular dependency with AMateria.hpp
// A forward declaration tells the compiler that a class exists without providing its full definition.
// Use #include when the full class definition is needed (e.g., when defining a member variable as an object).
// Use class ClassName; (forward declaration) when only a pointer or reference to the class is used in the header file.
class AMateria;

// interfaces typically do not need implementation files
// OCF does not have to be implemented for interfaces
class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif
