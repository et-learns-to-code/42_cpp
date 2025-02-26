/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:36:08 by etien             #+#    #+#             */
/*   Updated: 2025/02/26 16:57:35 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &src);
		Point &operator=(const Point &src);
		~Point();

		Fixed const &getX() const;
		Fixed const &getY() const;
};

// extractor operator overload to display coordinates of point
std::ostream &operator<<(std::ostream &out, Point const &point);

#endif
