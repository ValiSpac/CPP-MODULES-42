# include "inc/RPN.hpp"
# include <limits.h>

bool checkFormat(int ar, char *input)
{
	if (ar < 2)
	{
		std::cout << "Error: invalid argument!" << std::endl;
		return false;
	}
	int nb = 0;
	int op = 0;
	int i = 0;
	while (input[i])
	{
		if (isNum(input[i]))
			nb++;
		else if (isOperator(input[i]))
			op++;
		i++;
	}
	if (nb != op + 1)
	{
		std::cout << "Error: wrong format!" << std::endl;
		return false;
	}
	else if (nb == 1)
	{
		std::cout << "Error: only one argument!" << std::endl;
		return false;
	}
	return true;
}

int main(int argc, char **argv)
{
	if (!checkFormat(argc, argv[1]))
		return 1;
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
			float res = operation(a, b, argv[1][i]);
			if (res > INT_MAX)
			{
				std::cout << "Error: result bigger then max int!" << std::endl;
				return 1;
			}
			rpn.push(static_cast<int>(res));
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
