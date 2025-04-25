/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:02:32 by etien             #+#    #+#             */
/*   Updated: 2025/04/25 12:05:08 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// default constructor
PmergeMe::PmergeMe()
{
	// std::cout << "PmergeMe object default constructor called." << std::endl;
}

// copy constructor
PmergeMe::PmergeMe(const PmergeMe &src)
{
	// std::cout << "PmergeMe object copy constructor called." << std::endl;
	*this = src;
}

// assignment operator
PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	// std::cout << "PmergeMe object copy assignment operator called." << std::endl;
	// check for self-assignment
	if (this != &src)
	{
		this->_intVector = src._intVector;
		this->_intDeque = src._intDeque;
	}
	return *this;
}

// destructor
PmergeMe::~PmergeMe()
{
	// std::cout << "PmergeMe object destructor called." << std::endl;
}

// This function checks that the string is only composed of digits.
bool hasOnlyDigits(const std::string &input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		char c = input[i];
		if (!isdigit(c))
			return false;
	}
	return true;
}

// This helper function trims leading and trailing whitespaces from the input.
std::string trim(const std::string& input)
{
	// find the first non-whitespace character
	size_t start = input.find_first_not_of(" \t");
	// npos (no-position) means no matches
	if (start == std::string::npos)
		return ""; // If only whitespace characters, return empty string.
	 // find the last non-whitespace character
	size_t end = input.find_last_not_of(" \t");
	return input.substr(start, end - start + 1);
}

// 1) trim the string
// 2) check that it only contains digits and is a positive integer (no '-' allowed)
// 3) convert to long and test that the integer does not overflow
// 4) check for existing duplicates in the vector
// 5) add the number (as an integer) to the vector
void PmergeMe::createVector(char **av)
{
	while (*av)
	{
		std::string str(*av);
		str = trim(str);
		// hasOnlyDigits() will flag negative numbers too because of their negative sign
		if (!hasOnlyDigits(str))
			throw InvalidNumberException(str);
		// The third parameter is the number base. '10' indicates decimal.
		// strtol is called to check overflow before static_cast to int.
		long testInt = strtol(str.c_str(), NULL, 10);
		if (testInt > INT_MAX || testInt < INT_MIN)
			throw IntegerOverflowException(str);
		// std::find() returns an iterator to the found element or vec.end() if not found.
		if (std::find(_intVector.begin(), _intVector.end(), testInt) != _intVector.end())
			throw DuplicateNumberException(str);
		_intVector.push_back(static_cast<int>(testInt));		
		av++;
	}
	
	// DEBUG PRINT	
	for (std::vector<int>::iterator it = _intVector.begin(); it != _intVector.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
}

// Create the paired vector from the original vector and swap the numbers in each pair so that the
// bigger number occupies pair.first.
void createPairVector(std::vector<int> &_intVector, std::vector< std::pair<int, int> > &pairVector, int &straggler)
{
	std::vector<int>::const_iterator it = _intVector.begin();
	// add integer pair to pair vector
	while (it != _intVector.end())
	{
		int a = *it;
		it++;
		if (it ==  _intVector.end())
		{
			// since there isn't a second int to form a pair, that means a is a straggler
			straggler = a;
			break;
		}
		int b = *it;
		pairVector.push_back(std::pair<int, int>(a, b));
		it++;
	}		

	std::vector< std::pair<int, int> >::iterator pairIt;
	for (pairIt = pairVector.begin(); pairIt != pairVector.end(); pairIt++)
	{
		// access integer pairs with it->first and it->second
		if (pairIt->first < pairIt->second)
			// swaps the values of a and b
			std::swap(pairIt->first, pairIt->second);
	}

	//DEBUG PRINT
	std::cout << "Pair vector (big-sorted): ";
	for (std::vector< std::pair<int, int> >::iterator testIt = pairVector.begin(); testIt != pairVector.end(); testIt++)
		std::cout << testIt->first << " " << testIt-> second << " ";
	std::cout << "\n";
}

void merge(std::vector< std::pair<int, int> > &pairVector, int left, int mid, int right)
{
	// temp pair vector stores the sorted order that will be copied back to the paired vector
	std::vector< std::pair<int, int> > temp;
	// iterators to traverse each segment/half
	int i = left; // traverses left to before mid
	int j = mid; // traverses mid to before right
	
	while (i < mid && j < right)
	{
		// sorting order is based on the bigger number of each pair hence pair.first
		if (pairVector[i].first < pairVector[j].first)
			temp.push_back(pairVector[i++]);
		else
			temp.push_back(pairVector[j++]);
	}
	// handles cases where one segment has been fully added to temp but the other segment still has unadded pairs
	while (i < mid)
		temp.push_back(pairVector[i++]);
	while (j < right)
		temp.push_back(pairVector[j++]);
	// temp will overwrite the segment in the paired vector with the sorted order
	for (size_t k = 0; k < temp.size(); k++)
		pairVector[left + k] = temp[k];
}

// Performs recursive merge sort on the paired vector.
// Paired vector is recursively split into half until each segment has only one pair.
// Merge function will reassemble the segments in ascending order of pair.first.
void mergeSortPairVector(std::vector< std::pair<int, int> > &pairVector, int left, int right)
{
	// if range is 1 or less, it means you cannot split it anymore
	if (right - left <= 1)
		return;
	int mid = left + (right - left) / 2;
	// std::cout << "left: " << left << ", mid: " << mid << ", right: " << right << std::endl;
	mergeSortPairVector(pairVector, left, mid);
	mergeSortPairVector(pairVector, mid, right);
	merge(pairVector, left, mid, right);
}

// Ford Johnson Algorithm
// 1) Pair up adjacent numbers from the original vector and add them to a paired integer vector. Pairs will move together.
//    If there is a straggler with no pair, keep him aside. We will only involve him in the final sorted vector.
// 2) Swap places for each pair so that the bigger number is in front.
// 3) Recursively merge sort the pairs so that the bigger number of all pairs are in ascending order.
// 4) Copy over the first pair to the final vector and swap their places so that they are in ascending order. 
//    The final vector will contain the sorted sequence.
// 5) Copy over the bigger number of the remaining pairs to fill out the sorted sequence in the final vector.
// 6) The smaller number of each pair will now be binary inserted to the final vector following the index sequence
//    of the shifted and reversed Jacobsthal numbers (for index 3 onwards: 4, 3, 6, 5, 11, 10 ....).
// 7) Insert the straggler.
// Containers needed: Original vector (single) -> Paired vector (single) -> Final vector (single)
// Merge-insertion because:
// Merge - recursively sorting the big numbers
// Insertion - inserting the small numbers to the sorted big numbers
void PmergeMe::sortVector()
{
	std::vector< std::pair<int, int> > pairVector;
	// assign -1 to check for assignment because straggler must be a positive integer
	int straggler = -1;
	
	// handles 1) and 2)
	createPairVector(_intVector, pairVector, straggler);
	// handles 3)
	mergeSortPairVector(pairVector, 0, pairVector.size());

	// DEBUG PRINT
	std::cout << "Pair vector (ascending and big-sorted): ";
	for (std::vector< std::pair<int, int> >::iterator testIt = pairVector.begin(); testIt != pairVector.end(); testIt++)
		std::cout << testIt->first << " " << testIt-> second << " ";
	std::cout << "\n";	  
}

void PmergeMe::compare(char **av)
{	
	createVector(av);
	sortVector();
}

PmergeMe::ParsingException::ParsingException(std::string err) : _message(err) {}

PmergeMe::ParsingException::~ParsingException() throw() {}

const char *PmergeMe::ParsingException::what() const throw()
{
	return _message.c_str();
}

PmergeMe::InvalidNumberException::InvalidNumberException(std::string number)
: PmergeMe::ParsingException("Error: Invalid number : " + number) {}

PmergeMe::IntegerOverflowException::IntegerOverflowException(std::string number)
: PmergeMe::ParsingException("Error: Integer overflow : " + number) {}

PmergeMe::DuplicateNumberException::DuplicateNumberException(std::string number)
: PmergeMe::ParsingException("Error: Duplicate number : " + number) {}
