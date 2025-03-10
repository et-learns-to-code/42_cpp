/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:08:48 by etien             #+#    #+#             */
/*   Updated: 2025/03/10 18:47:31 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <iostream>

class Ice : public AMateria
{
	public:
		// OCF
		Ice();
		Ice(const Ice &src);
		Ice &operator=(const Ice &src);
		~Ice();

		// override of pure virtual functions in base class
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
