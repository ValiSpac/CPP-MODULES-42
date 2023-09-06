# include "inc/RPN.hpp"
# include <limits.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: invalid argument!" << std::endl;
		return 1;
	}
	int i = 0;
	int count = 0;
	while (!isOperator(argv[1][i]))
	{
		if (isNum(argv[1][i]))
			count++;
		i++;
	}
	if (count > 2)
	{
		std::cout << "Error: wrong format!" << std::endl;
		return 1;
	}
	std::stack<int> rpn;
	int a,b;
	for (int i = 0; argv[1][i]; i++)
	{
		if (isOperator(argv[1][i]))
		{
			if(rpn.size() < 2)
			{
				std::cout << "Error: bad input!" << std::endl;
				return (1);
			}
			a = rpn.top();
			rpn.pop();
			b = rpn.top();
			rpn.pop();
			float res = static_cast<float>(operation(a, b, argv[1][i]));
			if (res < INT_MIN || res > INT_MAX)
			{
				std::cout << "Error: result bigger then max int!" << std::endl;
				return 1;
			}
			rpn.push(operation(a, b, argv[1][i]));
		}
		else if (isNum(argv[1][i]))
		{
			if (isNum(argv[1][i + 1]))
			{
				std::cout << "Error" << std::endl;
				return 1;
			}
			rpn.push(argv[1][i] - 48);
		}
		else if (argv[1][i] != ' ')
		{
			std::cout << "Error" << std::endl;
			return 1;
		}
	}
	std::cout << rpn.top() << std::endl;
}
