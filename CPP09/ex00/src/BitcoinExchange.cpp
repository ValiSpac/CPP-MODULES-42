# include "../inc/BitcoinExchange.hpp"
#include <bits/stdc++.h>

bool isValidDate(std::string date)
{
	std::stringstream month(date.substr(4, 3));
	std::stringstream day(date.substr(7, 3));

	int month_n;
	month >> month_n;
	month_n *= -1;
	int day_n;
	day >> day_n;
	day_n *= -1;
	if (date.size() != 10)
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (i != 4 && i !=7)
		{
			if( !std::isdigit(date[i]))
				return false;
		}
		else if (date[i] != 45)
			return false;
	}
//	std::cout << date.substr(7, 3) << "----" << date.substr(4, 3) << std::endl;
	if (day_n > 30 || day_n < 0 || month_n > 12 || month_n < 0)
		return false;
	return true;
}

bool isNumericVal(const std::string& str)
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
		if (!std::isdigit(*it) && *it != 46)
			return false;
	return true;
}

bool checkDot(std::string value)
{
	for (size_t i = 0; i < value.length(); i++)
	{
		if (value[i] == '.')
		{
			if(value[i + 1] == '.')
				return false;
			return true;
		}
	}
	return true;
}

bool isValidNumber(std::string number)
{
	if (isNumericVal(number))
	{
		std::cout << "Error: bad input => " << number << std::endl;
		return false;
	}
	std::stringstream nb_s(number);
	float nb;
	nb_s >> nb;
	if (nb < 0)
	{
		std::cout << "Error: not a positive number" << std::endl;
		return false;
	}
	else if (nb > 1000)
	{
		std::cout << "Error: to large of a number" << std::endl;
		return false;
	}
	else if (!checkDot(number))
	{
		std::cout << "Error: bad input => " << number << std::endl;
		return false;
	}
	return true;
}

std::map<std::string, float> raedcsv()
{
	std::map<std::string, float> btc;
	std::string line;
	std::ifstream file("data.csv");
	std::string dateStr, valStr;
	if (!file.is_open())
	{
		std::cout << "Error : Can't open file" << std::endl;
		exit(1);
	}
	getline(file, line);
	while (getline(file, line))
	{
		std::stringstream lineStream(line);
		if (getline(lineStream, dateStr, ',') && getline(lineStream, valStr))
		{
			std::stringstream valbtc(valStr);
			float n;
			valbtc >> n;
			btc[dateStr] = n;
		}
	}
	file.close();
	return btc;
}
