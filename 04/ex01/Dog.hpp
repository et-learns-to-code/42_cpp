/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:02:28 by etien             #+#    #+#             */
/*   Updated: 2025/03/07 16:44:13 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#include <iostream>

class Dog : public Animal
{
	private:
		Brain *_brain;

	public:
		Dog();
		Dog(const Dog &src);
		Dog &operator=(const Dog &src);
		~Dog();

		void makeSound() const;

		Brain *getBrain() const;
};

#endif
