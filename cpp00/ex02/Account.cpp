/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:52 by etien             #+#    #+#             */
/*   Updated: 2025/02/17 12:00:46 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iostream>
#include <ctime> // for displayTimeStamp()

// Initializing static variables in global scope
// Static variables must be initialized in implementation file and not header.
// Initialization in header would violate C++’s One Definition Rule (ODR)
// because every .cpp file that includes this header would create its
// own copy of the static variable.
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Getters for static variables
// Return value must be Account::var because static members belong to
// the class, not to an instance.
int	Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

// Will display information about all accounts (i.e. totals) in this format:
// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
// Inside a static function, you can call another static function of the
// same class without prefacing it with Account::.
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout
	<< "accounts:" << getNbAccounts() << ";"
	<< "total:" << getTotalAmount() << ";"
	<< "deposits:" << getNbDeposits() << ";"
	<< "withdrawals:" << getNbWithdrawals() << ";"
	<< std::endl;
}

// Constructor should output account info in this format:
// [19920104_091532] index:0;amount:42;created
Account::Account( int initial_deposit ) :
_accountIndex(0), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	// assign account index (will start from 0)
	this->_accountIndex = Account::_nbAccounts;

	// increment static variables
	Account::_nbAccounts++;
	Account::_totalAmount += this->checkAmount();

	// print account creation message
	_displayTimestamp();
	std::cout
	<< "index:" << this->_accountIndex << ";"
	<< "amount:" << this->checkAmount() << ";"
	<< "created" << std::endl;
}

// Destructor should output account info in this format:
// [19920104_091532] index:0;amount:47;closed
Account::~Account( void )
{
	_displayTimestamp();
	std::cout
	<< "index:" << this->_accountIndex << ";"
	<< "amount:" << this->checkAmount() << ";"
	<< "closed" << std::endl;
}

// Will display deposit info in this format:
// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	Account::makeDeposit( int deposit )
{
	this->_nbDeposits++;

	_displayTimestamp();
	std::cout
	<< "index:" << this->_accountIndex << ";"
	<< "p_amount:" << this->checkAmount() << ";"
	<< "deposit:" << deposit << ";";

	this->_amount += deposit;

	std::cout
	<< "amount:" << this->checkAmount() << ";"
	<< "nb_deposits:" << this->_nbDeposits
	<< std::endl;

	// update static variables
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

// Will display withdrawal info in this format:
// [19920104_091532] index:0;p_amount:47;withdrawal:refused
//         or
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool	Account::makeWithdrawal( int withdrawal )
{
	this->_nbWithdrawals++;

	_displayTimestamp();
	std::cout
	<< "index:" << this->_accountIndex << ";"
	<< "p_amount:" << this->checkAmount() << ";"
	<< "withdrawal:" << withdrawal << ";";

	if (this->checkAmount() < withdrawal)
		std::cout
		<< "amount:" << this->checkAmount() << ";"
	else
	{
		this->_amount += deposit;

		std::cout
		<< "amount:" << this->checkAmount() << ";"
		<< "nb_deposits:" << this->_nbDeposits
		<< std::endl;

		// update static variables
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
	}
}

// Getter function for account balance that will be called in makeWithdrawal.
int		Account::checkAmount( void ) const
{
	return this->_amount;
}

// // Will display information about an account in this format:
// [19920104_091532] index:0;amount:47;deposits:1;withdrawals:0
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout
	<< "index:" << this->_accountIndex << ";"
	<< "amount:" << this->checkAmount() << ";"
	<< "deposits:" << this->_nbDeposits << ";"
	<< "withdrawals:" << this->_nbWithdrawals << ";"
	<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	// std::time_t now = std::time(nullptr);
	// Returns std::time_t (usually a long int), which is the number
	// of seconds elapsed since the Unix Epoch.
	// nullptr → Means "return the current time".

	// std::tm* localTime = std::localtime(&now);
	// Returns a std::tm* (pointer to a struct containing year, month,
	// day, hour, minute, second).
	// &now → A pointer to the std::time_t value.
	// Will convert seconds to a structured time representation.

	// std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localTime);
	// buffer: A character array to store the formatted timestamp.
	// sizeof(buffer): The maximum size of buffer (to prevent overflow).
	// "%Y%m%d_%H%M%S": The format string.
	// localTime: The std::tm* struct with date and time information.
	// Formats the structured std::tm time data into a human-readable string.

	// Conversion: Seconds (int) -> Time struct -> Time in string format
	std::time_t now = std::time(NULL);
	std::tm* localTime = std::localtime(&now);
	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", localTime);
	std::cout << buffer;
}
