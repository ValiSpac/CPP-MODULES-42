# include "../inc/Zombie.hpp"
# include <iostream>
# include <string>

using std::cout;
using std::cin;
using std::endl;

int	main(void)
{
	std::string	input;

	cout << "name the zombie on the stack:";
	getline(cin, input);
	if (cin.eof() == true)
	{
		cin.clear();
		cout << endl;
	}

	randomChump(input);

	cout << "name the zombie on the heap:";
	getline(cin, input);
	if (cin.eof() == true)
	{
		cin.clear();
		cout << endl;
	}

	Zombie	*newzombie = newZombie(input);

	delete newzombie;

	return 0;
}
