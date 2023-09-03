# include "DiamondTrap.hpp"
# include <iostream>

using	std::cout;
using	std::endl;

DiamondTrap::DiamondTrap() : ClapTrap("Default_DT_clap_name")
{
	this->name = "Default_DT";
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	cout << "Default DiamondTrap Constructor called" << endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	this->name = name;
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	cout << "DiamondTrap Constructor called with name" << name << endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& org) : ClapTrap(org) , ScavTrap(org) , FragTrap(org)
{
	*this = org;
	cout << "DiamondTrap Copy Constructor called"<< endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap&original)
{
	cout << "DiamondTrap Copy asignment operator called"<< endl;
	this->name = original.name;
	this->hit_points = original.hit_points;
	this->energy_points = original.energy_points;
	this->attack_damage = original.attack_damage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	cout << "Deconstructor DiamondTrap called" << endl;
}

void	DiamondTrap::attack(const std::string target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	cout << "My name is " << this->name << " and the name of my ClapTrap is " << ClapTrap::name << endl;
}
