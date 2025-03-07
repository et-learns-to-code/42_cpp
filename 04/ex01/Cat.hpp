/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:07:46 by etien             #+#    #+#             */
/*   Updated: 2025/03/07 16:46:46 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#include <iostream>

class Cat : public Animal
{
	private:
		Brain *_brain;

	public:
		Cat();
		Cat(const Cat &src);
		Cat &operator=(const Cat &src);
		~Cat();

		void makeSound() const;

		Brain *getBrain() const;
};

#endif
