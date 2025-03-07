/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:22:11 by etien             #+#    #+#             */
/*   Updated: 2025/03/07 15:53:51 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(const Brain &src);
		Brain &operator=(const Brain &src);
		~Brain();

		// const std::string & returns a reference to an existing string but prevents modification.
		// & avoids unnecessary copying, improves performance.
		// const after function	ensures the function does not modify the Brain object.
		const std::string &getIdea(const int &index) const;
		void setIdea(const std::string &idea, const int &index);
};

#endif
