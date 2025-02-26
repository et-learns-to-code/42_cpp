/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:07:11 by etien             #+#    #+#             */
/*   Updated: 2025/02/26 18:20:18 by etien            ###   ########.fr       */
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
	Point A(0, 0);
	Point B(5, 0);
	Point C(2.5, 5);
	Point P(0, 0);

	print(A, B, C, P); // expected: Inside

	Point A1(0, 0);
	Point B1(5, 0);
	Point C1(2.5, 5);
	Point P1(5, 5);

	print(A1, B1, C1, P1); // expected: Outside

	Point A2(-100, -100);
	Point B2(100, -100);
	Point C2(0, 100);
	Point P2(0, 0);

	print(A2, B2, C2, P2); // expected: Inside

	return 0;
}
