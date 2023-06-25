# include "../inc/Zombie.hpp"
# include <iostream>
# include <string>
# include <sstream>

using std::cout;
using std::cin;
using std::endl;

int	main(void)
{
	std::string	input;
	std::string	n;
	cout << "name the zombies on the heap:";
	getline(cin, input);
	cout << "name the number of zombies on the heap:";
	getline(cin, n);
	if (cin.eof() == true)
	{
		cin.clear();
		cout << endl;
	}

	std::stringstream	nb(n);
	int	x = 0;
	nb >> x;
	Zombie *zombies = zombieHorde(x, "Foo");

	for (int i = 0; i < x; i++)
		zombies[i].announce();

	delete[] zombies;
	return 0;
}
