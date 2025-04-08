/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:47:10 by etien             #+#    #+#             */
/*   Updated: 2025/04/08 19:33:35 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

// template <typename T> must be written above every single function template,
// even if they're all in the same file and use the same T, because each function
// template is a separate declaration, and the compiler needs to know that each
// one is templated independently.

// Swaps the values of two given arguments. Does not return anything.
template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

// Compares the two values passed in its arguments and returns the smallest one.
// If the two of them are equal, then it returns the second one.
template <typename T>
const T &min(const T &a, const T &b)
{
	return (a < b ? a : b);
}

// Compares the two values passed in its arguments and returns the greatest one.
// If the two of them are equal, then it returns the second one.
template <typename T>
const T &max(const T &a, const T &b)
{
	return (a > b ? a : b);
}

#endif
