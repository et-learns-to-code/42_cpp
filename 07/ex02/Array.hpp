/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:47:44 by etien             #+#    #+#             */
/*   Updated: 2025/04/09 17:46:45 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
class Array
{
	private:
		T* _arr;
		unsigned int _length;

	public:
		// OCF
		Array() : _arr(NULL), _length(0) {};
		Array(const Array &src) : _arr(src._arr), _length(src._length);
		Array &operator=(const Array &src);
		~Array();

		// Parameterized constructor
		Array(unsigned int n) : _arr(new Array[n]), _length(n) {}



};
