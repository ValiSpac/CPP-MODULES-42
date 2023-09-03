# pragma once

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    private:
        bool gate_guard;
    public:
        ScavTrap();
        ScavTrap(const ScavTrap& org);
        ScavTrap(std::string name);

        virtual ~ScavTrap();
        ScavTrap &operator=(const ScavTrap&original);

        void attack(const std::string target);
        void guardGate(void);
};
