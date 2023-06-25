#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
public:
    ClapTrap();
    ClapTrap(std::string name);
    ~ClapTrap();

    ClapTrap(const ClapTrap& orignial);
    ClapTrap &operator=(const ClapTrap&original);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

private:
    std::string name;
    int  hit_points;
    int  energy_points;
    int  attack_damage;

};

#endif
