/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:58:47 by etien             #+#    #+#             */
/*   Updated: 2025/03/07 14:15:11 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		Animal(const Animal &src);
		Animal &operator=(const Animal &src);
		virtual ~Animal();

		std::string getType() const;

		virtual void makeSound() const;
};

#endif
