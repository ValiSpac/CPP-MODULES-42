# include "HumanB.hpp"
# include <iostream>

HumanB::HumanB(std::string name) : name(name){}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}
