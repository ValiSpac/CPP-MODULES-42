# include "ClapTrap.hpp"
# include <iostream>

using std::cout;
using std::endl;

ClapTrap::ClapTrap()
{
    cout << "Default ClapTrap Constructor called" << endl;
    this->name = "rogue enemy";
    this->attack_damage = 0;
    this->energy_points = 10;
    this->hit_points = 100;
}

ClapTrap::ClapTrap(std::string name)
{
    cout << "Constructor ClapTrap called" << endl;
    this->name = name;
    this->attack_damage = 0;
    this->energy_points = 10;
    this->hit_points = 100;
}

ClapTrap::~ClapTrap()
{
    cout << "Deconstructor ClapTrap called" << endl;
}

ClapTrap::ClapTrap(const ClapTrap& original)
{
    cout << "Copy ClapTrap constructor called" << endl;
    this->name = original.name;
    this->attack_damage = original.attack_damage;
    this->energy_points = original.energy_points;
    this->hit_points = original.hit_points;
}

ClapTrap &ClapTrap::operator= (const ClapTrap& original)
{
    cout << "Copy ClapTrap assignment operator called" << endl;
    this->name = original.name;
    this->attack_damage = original.attack_damage;
    this->energy_points = original.energy_points;
    this->hit_points = original.hit_points;
    return (*this);
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->hit_points <= 0)
        cout << "ClapTrap::" << this->name << " is allready dead and can't attack!" << endl;
    if (this->energy_points <= 0)
        cout << this->name << " ran out of energy points " << endl;
    if (this->hit_points <= 0 || this->energy_points <= 0)
        return;
    cout << "ClapTrap::" << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << endl;
    this->energy_points--;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_points <= 0)
    {
        cout << this->name << " is allready dead!" << endl;
        return ;
    }
    cout << this->name << " lost " << amount << " of hitpoints!" << endl;
    this->hit_points -= amount;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energy_points <= 0)
        cout << this->name << " ran out of energy points " << endl;
    if (this->hit_points <= 0)
        cout << this->name << " is allready dead and can't be repaired!" << endl;
    if (this->hit_points <= 0 || this->energy_points <= 0)
        return;
    cout << this->name << " gained " << amount << " hitpoints!" << endl;
    this->hit_points += amount;
    this->energy_points--;
}
