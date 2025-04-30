/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:03:44 by etien             #+#    #+#             */
/*   Updated: 2025/04/30 14:11:47 by etien            ###   ########.fr       */
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

		// The four types of iterators found in containers:
		// iterator, const_iterator, reverse_iterator, const_reverse_iterator

		// We create a shorthand for the iterator types with a typedef.
		// The compiler will typically assume ::iterator to be a variable.
		// Since its resolution depends on the template parameter T (which is still unknown), the
		// the 'typename' keyword is necessary to assure the compiler that ::iterator is a type.
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		// c is the protected underlying container in std::stack.
		// These are intermediary begin/end functions that will return the values of the
		// begin/end member functions belonging to the underlying container.
		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
		// function overloading works for const and non-const functions.
		const_iterator begin() const {return this->c.begin();}
		const_iterator end() const {return this->c.end();}

		// rbegin() returns a reverse iterator pointing to the last element.
		// rend() returns a reverse iterator pointing to one before the first element.
		// When you're using a reverse_iterator, incrementing it (++it) actually moves you
		// backward in the underlying container — toward the beginning.
		reverse_iterator rbegin() {return this->c.rbegin();}
		reverse_iterator rend() {return this->c.rend();}
		const_reverse_iterator rbegin() const {return this->c.rbegin();}
		const_reverse_iterator rend() const {return this->c.rend();}
};

#endif
