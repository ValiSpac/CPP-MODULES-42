
# include <iostream>
# include "../inc/Zombie.hpp"

Zombie::~Zombie(void)
{
	std::cout << "Zombie "<< this->getName() << " died\n";
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

const std::string&	Zombie::getName(void) const
{
	return this->name;
}

void	Zombie::announce(void)
{
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
