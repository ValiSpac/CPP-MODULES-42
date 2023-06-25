# include "../inc/ScavTrap.hpp"
# include "../inc/FragTrap.hpp"
# include <iostream>

int main()
{
		ClapTrap a;
		ClapTrap b("Cody");

		a.attack("some other robot");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("some other other robot");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
			b.attack("Cody-clone");
		b.beRepaired(3);

		ScavTrap c;
		ScavTrap d("Wild");

		c.attack("CloneScavTrap");
		// for (int i = 0; i < 6; i++)
		// 	c.attack("CloneTrap");
		c.beRepaired(22);
		c.takeDamage(21);
		c.beRepaired(22);
		c.guardGate();
		c.guardGate();
		d.attack("Wildclone");
		d.takeDamage(101);
		d.takeDamage(15);
		d.attack("ScavTrapclone");

		FragTrap e;
		FragTrap f("Wild");

		e.attack("CloneFragTrap");
		// for (int i = 0; i < 5; i++)
		// 	e.attack("CloneTrap");
		e.beRepaired(22);
		e.takeDamage(21);
		e.beRepaired(22);
		e.highFiveGuys();
		e.highFiveGuys();
		f.attack("Wildclone");
		f.takeDamage(101);
		f.takeDamage(15);
		f.attack("FragTrapclone");
	return (0);
}

