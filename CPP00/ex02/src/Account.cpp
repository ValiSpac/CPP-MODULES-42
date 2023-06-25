/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpac <vpac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:38:25 by vpac              #+#    #+#             */
/*   Updated: 2023/06/22 11:44:25 by vpac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <ctime>
# include <iomanip>
# include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_nbAccounts += 1;
	this->_accountIndex = _nbAccounts - 1;
	this->_totalAmount += initial_deposit;
	this->_totalNbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex <<
				";ammount:" << this->_amount << ";created\n";
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
				<< ";amount:" << this->_amount << ";closed\n";
}

int	Account::getNbAccounts()
{
	return	_nbAccounts;
}

int	Account ::getTotalAmount()
{
	return	_totalAmount;
}

int	Account::getNbDeposits()
{
	return	_totalNbDeposits;
}
int	Account::getNbWithdrawals()
{
	return	_totalNbWithdrawals;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	t = std::time(0);
	std::tm* time = std::localtime(&t);
	std::cout << "[" << (time->tm_year + 1900);
	std::cout << std::setw(2) << time->tm_mon + 1;
	std::cout << std::setw(2) << time->tm_mday << "_";
	std::cout << std::setw(2) << time->tm_hour;
	std::cout << std::setw(2) << time->tm_min;
	std::cout << std::setw(2) << time->tm_sec;
	std::cout << "] ";
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals() << std::endl;
	return ;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount;
	this->_amount += deposit;
	this->_totalNbDeposits += 1;
	this->_totalAmount += deposit;
	this->_nbDeposits += 1;
	std::cout << ";deposit:" << deposit
				<< ";amount:" << this->_amount
				<< ";nb_deposits:" << this->_nbDeposits << std::endl;
	return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount
				<< ";withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refuesd\n";
		return (false);
	}
	this->_amount -= withdrawal;
	this->_totalNbWithdrawals += 1;
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals += 1;
	std::cout << withdrawal << ";amount:" << this->_amount
				<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int	Account::checkAmount(void) const
{
	if (this->_amount < 0)
		return (0);
	return (1);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
				<< ";amount" << this->_amount
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

