/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:37:48 by etien             #+#    #+#             */
/*   Updated: 2025/02/26 20:04:20 by etien            ###   ########.fr       */
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

	// cross product formula equivalent to α = area of triangle PBC / area of triangle ABC
	// The cross product measures area because it gives the signed determinant of a parallelogram
	// formed by two vectors. Since a triangle is just half of a parallelogram, the same formula
	// applies, just scaled accordingly.
	// Division by the denominator (area of the full triangle) is simply to normalize the weights.
	Fixed alpha = ((yB - yC) * (xP - xC) + (xC - xB) * (yP - yC)) / denominator;
	Fixed beta = ((yC - yA) * (xP - xC) + (xA - xC) * (yP - yC)) / denominator;
	Fixed gamma = Fixed(1) - alpha - beta;

	// If alpha, beta and gamma are all between 0 and 1, then the point is within the
	// triangle and the function will return true.
    // Edge: If the point lies on an edge, one of α,β,γ will be 0 because the corresponding
	//       sub-triangle collapses into a straight line, resulting in zero area.
	// Vertex: If the point coincides with a vertex, one of  α,β,γ will be exactly 1
	//         (meaning the point fully belongs to that vertex).
	// To correctly determine a point within a triangle, we exclude the edges and vertices
	// i.e. all weights are between 0 and 1 (excluding 0 and 1).
	return ((alpha > Fixed(0) && alpha < Fixed(1)) &&
			(beta > Fixed(0) && beta < Fixed(1)) &&
			(gamma > Fixed(0) && gamma < Fixed(1)));
}
