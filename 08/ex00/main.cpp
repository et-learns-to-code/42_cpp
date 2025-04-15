/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:54:41 by etien             #+#    #+#             */
/*   Updated: 2025/04/15 18:18:49 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <deque>

#define YELLOW "\033[33m"
#define RESET "\033[0m"

int main()
{
	{
		std::cout << YELLOW << "\nTEST: VECTOR CONTAINER" << RESET << std::endl;
		std::vector<int> intVector;
		intVector.push_back(0);
		intVector.push_back(1);
		intVector.push_back(2);
		intVector.push_back(3);
		intVector.push_back(4);
		intVector.push_back(5);
		intVector.push_back(6);
		printContainerContents(intVector);
		testEasyfind(intVector, 3);
		testEasyfind(intVector, 7);
	}
	{
		std::cout << YELLOW << "\nTEST: LIST CONTAINER" << RESET << std::endl;
		std::list<int> intList;
		intList.push_back(42);
		intList.push_back(-7);
		intList.push_back(13);
		intList.push_back(0);
		intList.push_back(99);
		intList.push_back(-42);
		intList.push_back(27);
		printContainerContents(intList);
		testEasyfind(intList, -13);
		testEasyfind(intList, -42);
	}
	{
		std::cout << YELLOW << "\nTEST: DEQUE CONTAINER" << RESET << std::endl;
		std::deque<int> intDeque;
		intDeque.push_back(5);
		intDeque.push_back(10);
		intDeque.push_back(15);
		intDeque.push_back(20);
		intDeque.push_back(25);
		intDeque.push_back(30);
		intDeque.push_back(35);
		printContainerContents(intDeque);
		testEasyfind(intDeque, 35);
		testEasyfind(intDeque, 45);
	}
	std::cout << std::endl;
	return 0;
}
