# include "ScavTrap.hpp"
# include <iostream>

using std::cout;
using std::endl;

ScavTrap::ScavTrap() : ClapTrap()
{
	cout << "Default ScavTrap Constructor called" << endl;
	this->gate_guard = false;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    cout << "Constructor ScavTrap called" << endl;
	this->gate_guard = false;
}

ScavTrap::ScavTrap(const ScavTrap& original) : ClapTrap(original)
{
    cout << "Copy ScavTrap constructor called" << endl;
	this->gate_guard = false;
}

ScavTrap::~ScavTrap()
{
    cout << "Deconstructor ScavTrap called" << endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap&original)
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	this->gate_guard = original.gate_guard;
    return (*this);
}

void	ScavTrap::attack(const std::string target)
{
    if (this->hit_points <= 0)
        cout << "ScavTrap::" << this->name << " is allready dead and can't attack!" << endl;
    if (this->energy_points <= 0)
        cout << this->name << " ran out of energy points " << endl;
    if (this->hit_points <= 0 || this->energy_points <= 0)
        return;
    cout << "ScavTrap::" << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << endl;
    this->energy_points--;
}

void	ScavTrap::guardGate(void)
{
	if (this->gate_guard == false)
	{
		this->gate_guard = true;
		cout << "ScavTrap::" << this->name << "is now guarding the gate!" << endl;
	}
	else
		cout << "ScavTrap::" << this->name << "is allready guarding the gate!" << endl;
}
