/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:21:14 by etien             #+#    #+#             */
/*   Updated: 2025/03/11 14:10:58 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"

#include <iostream>
#include <string>

class AMateria
{
	protected:
		std::string _type;

	public:
		// OCF
		AMateria();
		AMateria(const AMateria &src);
		AMateria &operator=(const AMateria &src);
		virtual ~AMateria();

		// custom constructor
		AMateria(std::string const & type);

		// Returns the materia type
		std::string const & getType() const;

		// pure virtual function does not have to be implemented for the base class
		virtual AMateria* clone() const = 0;

		virtual void use(ICharacter& target);
};

#endif
