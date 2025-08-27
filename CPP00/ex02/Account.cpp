#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// CONSTRUCTOR
Account::Account(int initial_deposit)
{
	// Initialising to 0
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	// Update info
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
	this->_amount = initial_deposit;
	this->_accountIndex = this->_nbAccounts - 1;

	// Print updated information
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"; 
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

// DESTRUCTOR
Account::~Account(void)
{
	// Print closing information
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"; 
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

// Displays summed data for all accounts
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

// displays info for a specific account
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"; 
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_totalAmount += deposit;
	_totalNbDeposits +=1;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"; 
	std::cout << "p_amount:" << this->_amount<< ";"; 
	std::cout << "deposit:" << deposit << ";"; 
	this->_amount += deposit;
	this->_nbDeposits += 1;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"; 
	std::cout << "p_amount:" << this->_amount<< ";"; 
	std::cout << "withdrawal:";
	if (this->_amount - withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal << ";";
	this->_amount -= withdrawal;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

void	Account::_displayTimestamp( void )
{
	time_t	timestamp = time(NULL);
	struct tm datetime = *localtime(&timestamp);
	char output[50];

	std::strftime(output, 50, "[%Y%m%d_%I%M%S] ", &datetime);
	std::cout << output;
}	
