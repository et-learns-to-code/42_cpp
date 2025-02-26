/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:37:48 by etien             #+#    #+#             */
/*   Updated: 2025/02/26 17:47:17 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed xA = a.getX();
	Fixed xB = b.getX();
	Fixed xC = c.getX();
	Fixed xP = point.getX();
	Fixed yA = a.getY();
	Fixed yB = b.getY();
	Fixed yC = c.getY();
	Fixed yP = point.getY();

	Fixed denominator = (yB - yC) * (xA - xC) + (xC - xB) * (yA - yC);

	Fixed alpha = ((yB - yC) * (xP - xC) + (xC - xB) * (yP - yC)) / denominator;
	Fixed beta = ((yC - yA) * (xP - xC) + (xA - xC) * (yP - yC)) / denominator;
	Fixed gamma = Fixed(1) - alpha - beta;

	// If alpha, beta and gamma are all between 0 and 1,
	// then the point is within the triangle and the function
	// will return true.
	return ((alpha >= Fixed(0) && alpha <= Fixed(1)) &&
			(beta >= Fixed(0) && beta <= Fixed(1)) &&
			(gamma >= Fixed(0) && gamma <= Fixed(1)));
}
