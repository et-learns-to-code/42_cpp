/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:08:14 by etien             #+#    #+#             */
/*   Updated: 2025/02/25 11:54:59 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

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
};

// Overloading of the insertion operator should be a regular
// non-member function i.e. outside the Fixed class because
// the left operand (std::ostream) is not a member of Fixed.
std::ostream &operator<<(std::ostream &out, Fixed const &fixed);

#endif
