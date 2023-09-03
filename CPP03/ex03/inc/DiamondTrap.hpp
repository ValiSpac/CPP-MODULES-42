# pragma once

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& org);

	DiamondTrap &operator=(const DiamondTrap&original);
	virtual ~DiamondTrap();

	void whoAmI();
	void attack(const std::string target);
private:
	std::string name;
};

