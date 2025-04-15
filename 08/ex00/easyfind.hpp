/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:45:29 by etien             #+#    #+#             */
/*   Updated: 2025/04/15 16:43:20 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // find()
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

// Assuming T is a container of integers, this function has to find the first
// occurrence of the second parameter in the first parameter.
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	// std::find
	// - parameters
	//   1) first, 2) last - input iterators
	//   3) value - value to search for in the range
	// - return value
	//   1) An iterator to the first element in the range that compares equal to val.
	// 	 2) If no elements match, the function returns last.
	// Returning container.end() mimics the std::find behaviour from <algorithm>.
	return (std::find(container.begin(), container.end(), value));
}

template <typename T>
void testEasyfind(T &container, int value)
{
	typename T::iterator it = easyfind(container, value);

	if (it == container.end())
		std::cout
			<< RED
			<< "Value (" << value << ") could not be found in the container."
			<< RESET;

	else
		// ✅ std::distance() gives you the zero-based index for containers that support
		// forward iteration (which all your sequential containers do).
		std::cout
			<< GREEN
			<< "Value (" << value << ") found at position "
			<< std::distance(container.begin(), it)
			<< " of the container."
			<< RESET;
}

template <typename T>
void printContainer(const T &container)
{
	std::cout << "Container contents: ";
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		std::cout << *it;
		// std::next(it) gives you the iterator after it.
		if (std::next(it) != container.end())
			std::cout << ", ";
	}
	std::cout << std::endl;
}

#endif
