# include "inc/easyfind.hpp"
# include <vector>
# include <map>

int main()
{
	std::vector<int> Vec;
	Vec.push_back(-5);
	Vec.push_back(42);
	Vec.push_back(66);
	Vec.push_back(9);
	Vec.push_back(2);
	try
	{
		std::cout << ::easyfind(Vec, -5) << std::endl;
		std::cout << ::easyfind(Vec, 42) << std::endl;
		std::cout << ::easyfind(Vec, 1444) << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
