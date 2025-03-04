/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:08:14 by etien             #+#    #+#             */
/*   Updated: 2025/02/25 11:53:05 by etien            ###   ########.fr       */
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
		Fixed(Fixed const &src);
		Fixed &operator=(Fixed const &src);
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
