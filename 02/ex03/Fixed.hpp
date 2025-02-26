/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:08:14 by etien             #+#    #+#             */
/*   Updated: 2025/02/25 21:57:26 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int _value;
		static const int _fraction;

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(Fixed const &src);
		Fixed &operator=(Fixed const &src);
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;

		// const member functions since they don't modify the objects
		// 6 comparison operators
		bool operator>(Fixed const &other) const;
		bool operator<(Fixed const &other) const;
		bool operator>=(Fixed const &other) const;
		bool operator<=(Fixed const &other) const;
		bool operator==(Fixed const &other) const;
		bool operator!=(Fixed const &other) const;
		// 4 arithmetic operators
		Fixed operator+(Fixed const &other) const;
		Fixed operator-(Fixed const &other) const;
		Fixed operator*(Fixed const &other) const;
		Fixed operator/(Fixed const &other) const;
		// 4 increment/decrement operators
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		// 4 min/max overloaded member functions
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed const &min(Fixed const &a, Fixed const &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static Fixed const &max(Fixed const &a, Fixed const &b);	
};

// Overloading of the insertion operator should be a regular
// non-member function i.e. outside the Fixed class because
// the left operand (std::ostream) is not a member of Fixed.
std::ostream &operator<<(std::ostream &out, Fixed const &fixed);

#endif
