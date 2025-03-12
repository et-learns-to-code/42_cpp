/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:08:14 by etien             #+#    #+#             */
/*   Updated: 2025/03/12 11:13:50 by etien            ###   ########.fr       */
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
		// OCF
		Fixed();
		Fixed(Fixed const &src);
		Fixed &operator=(Fixed const &src);
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
