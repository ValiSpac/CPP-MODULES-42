# include "inc/BitcoinExchange.hpp"

int main(int ac, char **argv)
{
	if (ac != 2)
	{
		std::cout << "Wrong usage!" << std::endl;
		return 0;
	}
	std::map<std::string, float> btc;
	std::string line,date,val;
	std::ifstream file(argv[1]);
	if (!file.is_open())
	{
		std::cout << "Error : Can't open file" << std::endl;
		exit(1);
	}
	btc = raedcsv();
	getline(file, line);
	while (getline(file, line))
	{
		std::stringstream linestream(line);
		if (getline(linestream, date, '|') && getline(linestream, val))
		{
			date.erase(date.find_last_not_of(" \t") + 1);
			float value = std::atof(val.c_str());
			if (!isValidNumber(val))
				continue;
			else if (!isValidDate(date))
				std::cout << "Error: bad input => " << date << std::endl;
			else
			{
				if (btc.find(date) != btc.end())
					std::cout << date << " => " << val << " = " << value * btc.at(date) << std::endl;
				else
				{
					std::map<std::string, float>::iterator it = btc.lower_bound(date);
					if (it != btc.end())
						it--;
					std::cout << date << " => " << val << " = " << value * it->second << std::endl;
				}
			}
		}
		else
			std::cout << "Error: bad input => " << date << std::endl;
	}
	return 0;
}
