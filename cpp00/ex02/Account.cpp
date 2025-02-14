/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:52 by etien             #+#    #+#             */
/*   Updated: 2025/02/14 18:50:14 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

// Initializing static variables in global scope
// Static variables must be initialized in implementation file and not header.
// Initialization in header would violate C++’s One Definition Rule (ODR)
// because every .cpp file that includes this header would create its
// own copy of the static variable.
int Account::_nbAccounts = 0;
int Account::_nbAccounts = 0;
int Account::_nbAccounts = 0;
int Account::_nbAccounts = 0;

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

void	Account::displayAccountsInfos( void )
{

}


Account::Account( int initial_deposit ) :
_accountIndex(0), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
}

Account::~Account( void )
{

}


void	Account::makeDeposit( int deposit )
{

}

bool	Account::makeWithdrawal( int withdrawal )
{

}

int		Account::checkAmount( void ) const
{

}

void	Account::displayStatus( void ) const
{

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

	std::cout << "[ " << time << " ]" << std::endl
}
