/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:37:23 by etien             #+#    #+#             */
/*   Updated: 2025/04/09 13:46:42 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib> // size_t
#include <iostream>

// A function template iter that takes 3 parameters and returns nothing.
// The first parameter is the address of an array.
// The second one is the length of the array.
// The third one is a function that will be called on every element of the array.
// void (*func)(T&)
// - The * in (*func) is part of the declaration syntax for a function pointer (not dereferencing).
// - Function pointers are automatically dereferenced when called so we can write func(arr[i])
//   instead of (*func)(x).
// - void is the return type.
// - T& is the parameter type (a reference to T data type).
template <typename T>
void iter(T *arr, size_t length, void (*func)(T&))
{
	for (size_t i = 0; i < length; i++)
		// Function pointers are automatically dereferenced when called.
		func(arr[i]);
}

// This template will print out the item to the terminal and append a space behind it.
template <typename T>
void printItem(T& item)
{
	std::cout << item << " ";
}

#endif
