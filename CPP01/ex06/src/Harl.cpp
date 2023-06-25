# include "Harl.hpp"
# include <iostream>

# define DEBUG "[I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!]"
# define INFO "[I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!]"
# define WARNING "[I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.]"
# define ERROR "[This is unacceptable! I want to speak to the manager now.]"

using	std::cout;
using	std::endl;

Harl::Harl(void){}

Harl::~Harl(void){}

void	Harl::debug(void)
{
	cout << DEBUG << endl;
}

void	Harl::info(void)
{
	cout << INFO << endl;
}

void	Harl::warning(void)
{
	cout << WARNING << endl;
}

void	Harl::error(void)
{
	cout << ERROR << endl;
}

void	Harl::complain(std::string level)
{
	harl_func func[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4]= {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < 4; i++)
		if (level == levels[i])
		{
			switch (i)
			{
			case 0:
				(this->*func[0])();
				(this->*func[1])();
				(this->*func[2])();
				(this->*func[3])();
				break;
			case 1:
				(this->*func[1])();
				(this->*func[2])();
				(this->*func[3])();
				break;
			case 2:
				(this->*func[2])();
				(this->*func[3])();
				break;
			case 3:
				(this->*func[3])();
				break;
			default:
				break;
			}
			return ;
		}
	cout << "[Probably complaining about insignificant problems]" << endl;
	return;
}
