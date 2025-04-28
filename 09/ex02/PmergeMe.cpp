/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:02:32 by etien             #+#    #+#             */
/*   Updated: 2025/04/28 17:31:06 by etien            ###   ########.fr       */
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
		this->_originalVector = src._originalVector;
		this->_pairVector = src._pairVector;
		this->_sortedVector = src._sortedVector;

		this->_originalDeque = src._originalDeque;
		this->_pairDeque = src._pairDeque;
		this->_sortedDeque = src._sortedDeque;
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
void PmergeMe::createOriginalVector(char **av)
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
		if (std::find(_originalVector.begin(), _originalVector.end(), testInt) != _originalVector.end())
			throw DuplicateNumberException(str);
		_originalVector.push_back(static_cast<int>(testInt));
		av++;
	}

	#ifdef DEBUG
		for (std::vector<int>::iterator it = _originalVector.begin(); it != _originalVector.end(); it++)
			std::cout << *it << " ";
		std::cout << "\n";
	#endif
}

// Create the paired vector from the original vector and swap the numbers in each pair so that the
// bigger number occupies pair.first.
void PmergeMe::createPairVector(int &straggler)
{
	std::vector<int>::const_iterator it = _originalVector.begin();
	// add integer pair to pair vector
	while (it != _originalVector.end())
	{
		int a = *it;
		it++;
		if (it ==  _originalVector.end())
		{
			// since there isn't a second int to form a pair, that means a is a straggler
			straggler = a;
			break;
		}
		int b = *it;
		_pairVector.push_back(std::pair<int, int>(a, b));
		it++;
	}

	std::vector< std::pair<int, int> >::iterator pairIt;
	for (pairIt = _pairVector.begin(); pairIt != _pairVector.end(); pairIt++)
	{
		// access integer pairs with it->first and it->second
		if (pairIt->first < pairIt->second)
			// swaps the values of a and b
			std::swap(pairIt->first, pairIt->second);
	}

	#ifdef DEBUG
		std::cout << "Pair vector (big-sorted): ";
		for (std::vector< std::pair<int, int> >::iterator testIt = _pairVector.begin(); testIt != _pairVector.end(); testIt++)
			std::cout << testIt->first << " " << testIt-> second << " ";
		std::cout << "\n";
	#endif
}

void PmergeMe::mergePairVector(int left, int mid, int right)
{
	// temp pair vector stores the sorted order that will be copied back to the paired vector
	std::vector< std::pair<int, int> > temp;
	// iterators to traverse each segment/half
	int i = left; // traverses left to before mid
	int j = mid; // traverses mid to before right

	while (i < mid && j < right)
	{
		// sorting order is based on the bigger number of each pair hence pair.first
		if (_pairVector[i].first < _pairVector[j].first)
			temp.push_back(_pairVector[i++]);
		else
			temp.push_back(_pairVector[j++]);
	}
	// handles cases where one segment has been fully added to temp but the other segment still has unadded pairs
	while (i < mid)
		temp.push_back(_pairVector[i++]);
	while (j < right)
		temp.push_back(_pairVector[j++]);
	// temp will overwrite the segment in the paired vector with the sorted order
	for (size_t k = 0; k < temp.size(); k++)
		_pairVector[left + k] = temp[k];
}

// Performs recursive merge sort on the paired vector to sort the bigger integers in ascending order.
// Paired vector is recursively split into half until each segment has only one pair.
// Merge function will reassemble the segments in ascending order of pair.first.
void PmergeMe::mergeSortPairVector(int left, int right)
{
	// if range is 1 or less, it means you cannot split it anymore
	if (right - left <= 1)
		return;
	int mid = left + (right - left) / 2;
	// std::cout << "left: " << left << ", mid: " << mid << ", right: " << right << std::endl;
	mergeSortPairVector(left, mid);
	mergeSortPairVector(mid, right);
	mergePairVector(left, mid, right);

	#ifdef DEBUG
		std::cout << "Pair vector (ascending and big-sorted): ";
		for (std::vector< std::pair<int, int> >::iterator testIt = _pairVector.begin(); testIt != _pairVector.end(); testIt++)
			std::cout << testIt->first << " " << testIt-> second << " ";
		std::cout << "\n";
	#endif
}

// Adds the first pair and copies over all the sorted bigger integers to the sorted vector.
void PmergeMe::createSortedVector()
{
	// adding the smaller integer of the first pair in the paired vector sequence
	_sortedVector.push_back(_pairVector[0].second);
	// adding the bigger integer of the first pair in the paired vector sequence
	_sortedVector.push_back(_pairVector[0].first);
	std::vector< std::pair<int, int> >::const_iterator pairIt;
	// ++begin() to skip past the first pair which has already been added
	for (pairIt = ++_pairVector.begin(); pairIt != _pairVector.end(); pairIt++)
		// copying over the bigger integer of all the other pairs
		_sortedVector.push_back(pairIt->first);

	#ifdef DEBUG
		std::cout << "Sorted vector (before insertion): ";
		for (std::vector<int>::iterator testIt = _sortedVector.begin(); testIt != _sortedVector.end(); testIt++)
			std::cout << *testIt << " ";
		std::cout << "\n";
	#endif
}

// The index generated here is an array index. The value will be between 1 and (n - 1).
// We don't need index 0 because pair[0] has already been sorted.
// n is the size of the paired vector.
void PmergeMe::generateIndexSequence(int n, std::vector<int> &index)
{
	std::vector<int> groupSize;
	groupSize.push_back(2);
	int totalGroupSize = 2;
	int power = 2;

	while (totalGroupSize < n)
	{
		// Adjacent group sizes are a rising power of 2 sequence.
		// 2, 2, 6, 10
		// 2 + 2 = 4 = 2^2
		// 2 + 6 = 8 = 2^3
		// 6 + 10 = 16 = 2^4
		int nextGroupSize = std::pow(2, power) - groupSize.back();
		if (totalGroupSize + nextGroupSize < n)
			groupSize.push_back(nextGroupSize);
		// truncate last group to fit wihin n indexing
		else
			// -1 because of array indexing
			groupSize.push_back(n - 1 - totalGroupSize);
		totalGroupSize += nextGroupSize;
		power++;
	}
	int baseIndex = 0;
	for (size_t sizeIt = 0; sizeIt < groupSize.size(); sizeIt++)
	{
		for (int size = groupSize[sizeIt]; size > 0; size--)
			// size will be >= 1 so index will also be >=1;
			index.push_back(baseIndex + size);
		baseIndex += groupSize[sizeIt];
	}

	// should generate 1-99 sequence for n = 100:
	// 2 1 4 3 10 9 8 7 6 5 20 19 18 17 16 15 14 13 12 11 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21
	// 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43
	// 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85
	#ifdef DEBUG
		std::cout << "Index sequence: ";
		for (std::vector<int>::iterator testIt = index.begin(); testIt != index.end(); testIt++)
			std::cout << *testIt << " ";
		std::cout << "\n";
	#endif
}

// Binary search insertion of the smaller integers to the sorted vector in the index order of the reversed and shifted Jacobsthal sequence.
void PmergeMe::insertToSortedVector()
{
	std::vector<int> index;

	generateIndexSequence(_pairVector.size(), index);

	for (size_t i = 0 ; i < index.size(); i++)
	{
		int integer =  _pairVector[index[i]].second;
		int integerPair = _pairVector[index[i]].first;
		// Since the smaller integer will definitely be smaller than its pair, the search space is narrowed
		// to right before its pair's position in the sorted vector.
		std::vector<int>::iterator pairPos = std::find(_sortedVector.begin(), _sortedVector.end(), integerPair);
		// binary search for the insertion point with std::lower_bound()
		std::vector<int>::iterator insertPos = std::lower_bound(_sortedVector.begin(), pairPos, integer);
		_sortedVector.insert(insertPos, integer);

		#ifdef DEBUG
			std::cout << "Integer added: " << integer << " from index " << index[i] << "\n";
			std::cout << "Sorted vector (after insertion): ";
			for (std::vector<int>::iterator testIt = _sortedVector.begin(); testIt != _sortedVector.end(); testIt++)
				std::cout << *testIt << " ";
			std::cout << "\n";
		#endif
	}
}

// Ford Johnson Algorithm
// 1) Pair up adjacent numbers from the original vector and add them to a paired integer vector. Pairs will move together.
//    If there is a straggler with no pair, keep him aside. We will only involve him in the sorted vector.
// 2) Swap places for each pair so that the bigger number is in front.
// 3) Recursively merge sort the pairs so that the bigger number of all pairs are in ascending order.
// 4) Copy over the first pair to the sorted vector and swap their places so that they are in ascending order.
// 5) Copy over the bigger number of the remaining pairs to fill out the sorted sequence in the sorted vector.
// 6) The smaller number of each pair will now be binary search inserted to the sorted vector following the index
//    sequence of the shifted and reversed Jacobsthal numbers.
// 7) Insert the straggler.
// Containers needed: Original vector (single) -> Paired vector (single) -> Sorted vector (single)
// Merge-insertion because:
// Merge - recursively sorting the big numbers
// Insertion - inserting the small numbers to the sorted big numbers
void PmergeMe::sortVector(char **av)
{
	createOriginalVector(av);

	// assign -1 to check for assignment because straggler must be a positive integer
	int straggler = -1;

	// handles 1) and 2)
	createPairVector(straggler);
	// handles 3)
	mergeSortPairVector(0, _pairVector.size());
	// handles 4) and 5)
	createSortedVector();
	// handles 6)
	insertToSortedVector();

	// handles 7)
	if (straggler >= 0)
	{
		std::vector<int>::iterator stragglerPos = std::lower_bound(_sortedVector.begin(), _sortedVector.end(), straggler);
		_sortedVector.insert(stragglerPos, straggler);

		#ifdef DEBUG
			std::cout << "Sorted vector (after inserting straggler): ";
			for (std::vector<int>::iterator testIt = _sortedVector.begin(); testIt != _sortedVector.end(); testIt++)
				std::cout << *testIt << " ";
			std::cout << "\n";
		#endif
	}
}

void PmergeMe::compare(char **av)
{
	sortVector(av);
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
