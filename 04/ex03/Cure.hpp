/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:19:40 by etien             #+#    #+#             */
/*   Updated: 2025/03/10 18:47:36 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <iostream>

class Cure : public AMateria
{
	public:
		// OCF
		Cure();
		Cure(const Cure &src);
		Cure &operator=(const Cure &src);
		~Cure();

		// override of pure virtual functions in base class
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
