/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:47:44 by etien             #+#    #+#             */
/*   Updated: 2025/04/10 14:29:26 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
	private:
		T* _arr;
		unsigned int _size;

	public:
		// OCF
		// Constructor - creates an empty array
		Array() : _arr(NULL), _size(0) {}
		Array(const Array &src)
		{
			*this = src;
		}
		Array &operator=(const Array &src)
		{
			if (this != &src)
			{
				// delete original array before reallocating to prevent memory leaks
				delete[] this->_arr;
				// allocate a T array
				this->_arr = new T[src.size()]();
				// individually copy over contents of array to ensure deep copy
				for (unsigned int i = 0; i < src.size(); i++)
					this->_arr[i] = src._arr[i];
				this->_size = src.size();
			}
			return *this;
		}
		// Destructor - should free the allocated array
		~Array()
		{
			delete[] this->_arr;
		};

		// Parameterized constructor
		// - creates an array of n elements initialized by default.
		// new T[n]() will initialize the values to the default.
		// new T[n] without the brackets leaves the values uninitialized and
		// they could still contain garbage values.
		// default initialization is 0 for built-in types while the default
		// constructor will be called for class types.
		Array(unsigned int n) : _arr(new T[n]()), _size(n) {}

		// Subscript operator overload
		// - elements can be accessed with the subscript operator: [ ]
		// - compiler understands that the index value is between the brackets
		T& operator[](unsigned int index)
		{
			// unnecessary to check for index < 0 since unsigned int is used
			if (index >= this->_size)
				// Passing a string to a standard exception sets its internal error message,
				// which will be returned by the .what() method.
				throw std::out_of_range("Index is out of bounds.");
			return this->_arr[index];
		}

		// Getter - returns the number of elements in the array.
		// This member function takes no parameter and musn’t
		// modify the current instance.
		unsigned int size() const
		{
			return this->_size;
		}
};

#endif
