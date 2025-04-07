/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:59:59 by etien             #+#    #+#             */
/*   Updated: 2025/04/07 19:39:14 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <stdint.h> // uintptr_t

struct Data
{
	int id;
	std::string name;
};

class Serializer
{
	private:
		// OCF - put into private so that class cannot be instantiated by users
		Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);
		~Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
