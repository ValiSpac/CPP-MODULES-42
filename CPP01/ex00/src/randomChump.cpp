# include <iostream>
# include "../inc/Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	newzombie;

	newzombie.setName(name);
	newzombie.announce();
}
