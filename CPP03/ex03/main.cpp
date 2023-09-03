# include <iostream>
# include "DiamondTrap.hpp"

int main()
{
	DiamondTrap a;
	DiamondTrap b("Test_Trap");

	a.attack("some other robot");
	a.takeDamage(10);
	a.takeDamage(10);
	a.beRepaired(5);
	b.attack("some other other robot");
	b.beRepaired(3);
	for (int i = 0; i < 12; i++)
		b.attack("Cody-clone");
	b.beRepaired(3);
	a.whoAmI();
	b.whoAmI();
}
