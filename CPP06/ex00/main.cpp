# include "Scalar.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong usage!" << std::endl;
		return (1);
	}
	std::string input = argv[1];

	Scalar::convert(input);
	return (0);
}
