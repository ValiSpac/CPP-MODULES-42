# include <iostream>
# include <string>
# include "Harl.hpp"

bool		is_input_valid(std::string input)
{
	if (input != "DEBUG" && input != "INFO" && input != "WARNING" && input != "ERROR")
		return false;
	return true;
}

int main()
{
	Harl		harl;
	std::string	input;

	while (1)
	{
		std::cout << "\nInput a level of complain for Harl: (DEBUG, INFO, WARNING, ERROR)\n";
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cin.clear();
			return 0;
		}
		if (!is_input_valid(input) || input.empty())
			return (std::cout << "Invalid input!\n", 1);
		harl.complain(input);
	}
	return 0;
}
