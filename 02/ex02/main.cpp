/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:07:11 by etien             #+#    #+#             */
/*   Updated: 2025/02/25 21:52:13 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	
	return 0;
}

// $> ./a.out
// 0
// 0.00390625
// 0.00390625
// 0.00390625
// 0.0078125
// 10.1016
// 10.1016

// // Main for comprehensive testing
// int main() {
// 	Fixed a(5.5f);
// 	Fixed b(2);
// 	Fixed c(5.5f);

// 	std::cout << "Testing Comparison Operators:" << std::endl;
// 	std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
// 	std::cout << "a > b: " << (a > b) << std::endl;
// 	std::cout << "a < b: " << (a < b) << std::endl;
// 	std::cout << "a >= c: " << (a >= c) << std::endl;
// 	std::cout << "a <= c: " << (a <= c) << std::endl;
// 	std::cout << "a == c: " << (a == c) << std::endl;
// 	std::cout << "a != c: " << (a != c) << std::endl;
	
// 	std::cout << "\nTesting Arithmetic Operators:" << std::endl;
// 	std::cout << "a + b: " << (a + b) << std::endl;
// 	std::cout << "a - b: " << (a - b) << std::endl;
// 	std::cout << "a * b: " << (a * b) << std::endl;
// 	std::cout << "a / b: " << (a / b) << std::endl;

// 	std::cout << "\nTesting Increment/Decrement Operators:" << std::endl;
// 	Fixed d(3.3f);
// 	std::cout << "d: " << d << std::endl;
// 	std::cout << "Pre-increment: " << ++d << std::endl;
// 	std::cout << "Post-increment: " << d++ << " (before increment)" << std::endl;
// 	std::cout << "After post-increment: " << d << std::endl;
// 	std::cout << "Pre-decrement: " << --d << std::endl;
// 	std::cout << "Post-decrement: " << d-- << " (before decrement)" << std::endl;
// 	std::cout << "After post-decrement: " << d << std::endl;

// 	std::cout << "\nTesting Min/Max Functions:" << std::endl;
// 	Fixed e(10.5f), f(7.2f);
// 	std::cout << "Min between " << e << " and " << f << ": " << Fixed::min(e, f) << std::endl;
// 	std::cout << "Max between " << e << " and " << f << ": " << Fixed::max(e, f) << std::endl;

// 	return 0;
// }
