/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:03:44 by etien             #+#    #+#             */
/*   Updated: 2025/04/17 13:42:20 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

// The goal of this exercise is to create an iterable stack.
// Stacks are container adapters that have an underlying container.
// To make the stack iterable, we have to reach into the stack to
// access the already existing container iterator.

// Subject:
// Write a MutantStack class. It will be implemented in terms of a std::stack.
// It will offer all its member functions, plus an additional feature: iterators.
template <typename T>
// Creating a template class - a mutant stack that can store all data types.
class MutantStack : public std::stack<T>
{
	public:
		// OCF
		// default constructor
		MutantStack() {}
		// copy constructor
		// explicitly call stack's copy constructor to prevent its default constructor from being called instead.
		MutantStack(const MutantStack &src) : std::stack<T>(src) {}
		// assignment operator overload
		MutantStack &operator=(const MutantStack &src)
		{
			if (this != &src)
				// delegating the assignment to the base class.
				// actual stack contents are stored in std::stack<T>, so its assignment operator
				// will know how to copy over the contents.
				// std::stack<T>:: is to qualify that we are using the operator overload from the base class
				// so that the namespace is clear.
				std::stack<T>::operator=(src);
			return *this;
		}
		// destructor
		~MutantStack() {}

		// four iterator types found in containers
		typedef


};

#endif
