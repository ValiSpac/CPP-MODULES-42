# include "../inc/FragTrap.hpp"
# include <iostream>

using std::cout;
using std::endl;

FragTrap::FragTrap() : ClapTrap()
{
	cout << "Default FragTrap Constructor called" << endl;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    cout << "Constructor FragTrap called" << endl;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& original) : ClapTrap(original)
{
	cout << "Copy FragTrap constructor called" << endl;
	this->attack_damage = original.attack_damage;
	this->energy_points = original.energy_points;
}

FragTrap::~FragTrap()
{
	cout << "Deconstructor FragTrap called" << endl;
}

FragTrap &FragTrap::operator=(const FragTrap&original)
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
	if (this != &original)
	{
		this->name = original.name;
		this->hit_points = original.hit_points;
		this->energy_points = original.energy_points;
		this->attack_damage = original.attack_damage;
	}
	return (*this);
}

void	FragTrap::attack(const std::string target)
{
	if (this->hit_points <= 0)
		cout << "FragTrap::" << this->name << " is allready dead and can't attack!" << endl;
	if (this->energy_points <= 0)
		cout << this->name << " ran out of energy points " << endl;
	if (this->hit_points <= 0 || this->energy_points <= 0)
		return;
	cout << "FragTrap::" << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << endl;
	this->energy_points--;
}

void	FragTrap::highFiveGuys(void)
{
	cout << "HighFive!" << endl;
}
