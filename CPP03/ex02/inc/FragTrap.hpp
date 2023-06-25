# pragma once

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& org);

	FragTrap &operator=(const FragTrap&original);
	virtual ~FragTrap();

	void attack(const std::string target);
	void highFiveGuys(void);
};

