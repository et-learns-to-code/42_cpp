/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:21:12 by etien             #+#    #+#             */
/*   Updated: 2025/03/11 15:28:35 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

#include <iostream>
#include <string>

class MateriaSource : public IMateriaSource
{
	private:
		static const int _templatesSize = 4;
		AMateria *_templates[_templatesSize];

	public:
		// OCF
		MateriaSource();
		MateriaSource(const MateriaSource &src);
		MateriaSource &operator=(const MateriaSource &src);
		~MateriaSource();

		// override of pure virtual functions in base class
		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const & type);
};

#endif
