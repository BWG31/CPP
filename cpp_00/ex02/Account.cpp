#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
	:	_accountIndex(_nbAccounts),
		_amount(initial_deposit),
		_nbDeposits(0),
		_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout 
		<< "index:" << _accountIndex \
		<< ";amount:" << _amount \
		<< ";created" << std::endl;
}

Account::~Account()
{
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
	_displayTimestamp();
	std::cout \
		<< "index:" << _accountIndex \
		<< ";amount:" << _amount \
		<< ";closed" << std::endl;
}

void Account::_displayTimestamp()
{
	std::time_t current_time = std::time(nullptr);
	std::tm *local_time = std::localtime(&current_time);
	std::cout << '[' << std::put_time(local_time, "%Y%m%d_%H%M%S") << "] ";
}

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::getTotalAmount()
{
	return(_totalAmount);
}

int Account::getNbDeposits()
{
	return(_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return(_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout 
		<< "accounts:" << getNbAccounts() \
		<< ";total:" << getTotalAmount() \
		<< ";deposits:" << getNbDeposits() \
		<< ";withdrawals:" << getNbWithdrawals() \
		<< std::endl;
	return ;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex \
		<< ";p_amount:" << _amount \
		<< ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits ++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout
		<< ";amount:" << _amount \
		<< ";nb_deposits:" << _nbDeposits \
		<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex \
		<< ";p_amount:" << _amount \
		<< ";withdrawal:";
	if (withdrawal > checkAmount())
		std::cout << "refused";
	else
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << withdrawal \
		<< ";amount:" << _amount \
		<< ";nb_withdrawals:" << _nbWithdrawals;
	}
	std::cout << std::endl;
	return (true);
}

int Account::checkAmount() const
{
	return (_amount);
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout \
		<< "index:" << _accountIndex \
		<< ";amount:" << _amount \
		<< ";deposits:" << _nbDeposits \
		<< ";withdrawals:" << _nbWithdrawals \
		<< std::endl;
	return ;
}
