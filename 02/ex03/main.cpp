/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:07:11 by etien             #+#    #+#             */
/*   Updated: 2025/02/26 20:20:18 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

void print(Point const a, Point const b, Point const c, Point const point)
{
	std::cout << "A: " << a << std::endl
			<< "B: " << b << std::endl
			<< "C: " << c << std::endl
			<< "Point: " << point << std::endl;

	if (bsp(a, b, c, point))
		std::cout << "Point is within the triangle." << std::endl << std::endl;
	else
		std::cout << "Point is outside the triangle." << std::endl << std::endl;
}

int main( void )
{
	// 1. Point is inside the triangle
	Point A1(0, 0);
	Point B1(5, 0);
	Point C1(2.5, 5);
	Point P1(2.5, 2); // Expected: Inside
	print(A1, B1, C1, P1);

	// 2. Point is exactly on a vertex
	Point A2(0, 0);
	Point B2(5, 0);
	Point C2(2.5, 5);
	Point P2(0, 0); // Expected: Outside (vertex)
	print(A2, B2, C2, P2);

	// 3. Point is on an edge
	Point A3(0, 0);
	Point B3(5, 0);
	Point C3(2.5, 5);
	Point P3(2.5, 0); // Expected: Outside (edge)
	print(A3, B3, C3, P3);

	// 4. Point is outside but near an edge
	Point A4(0, 0);
	Point B4(5, 0);
	Point C4(2.5, 5);
	Point P4(2.5, -0.1); // Expected: Outside
	print(A4, B4, C4, P4);

	// 5. Point is far outside the triangle
	Point A5(-10, -10);
	Point B5(10, -10);
	Point C5(0, 10);
	Point P5(20, 20); // Expected: Outside
	print(A5, B5, C5, P5);

	// 6. Triangle with negative coordinates, point inside
	Point A6(-5, -5);
	Point B6(5, -5);
	Point C6(0, 5);
	Point P6(0, 0); // Expected: Inside
	print(A6, B6, C6, P6);

	// 7. Triangle with negative coordinates, point outside
	Point A7(-5, -5);
	Point B7(5, -5);
	Point C7(0, 5);
	Point P7(-10, -10); // Expected: Outside
	print(A7, B7, C7, P7);

	// 8. Degenerate case: all points are collinear
	Point A8(0, 0);
	Point B8(5, 0);
	Point C8(10, 0);
	Point P8(2.5, 0); // Expected: Outside (edge)
	print(A8, B8, C8, P8);

	// 9. Large triangle with point inside
	Point A10(-1000, -1000);
	Point B10(1000, -1000);
	Point C10(0, 1000);
	Point P10(0, 0); // Expected: Inside
	print(A10, B10, C10, P10);

	// 10. Large triangle with point outside
	Point A11(-1000, -1000);
	Point B11(1000, -1000);
	Point C11(0, 1000);
	Point P11(1500, 1500); // Expected: Outside
	print(A11, B11, C11, P11);

	return 0;
}
