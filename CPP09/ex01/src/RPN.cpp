# include "RPN.hpp"

bool isOperator(char op)
{
	if (op == '+' || op == '-' || op == '/' || op == '*')
		return true;
	return false;
}

int operation(int a, int b, char op)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (b - a);
	if (op == '*')
		return (a * b);
	if (op == '/')
	{
		if (a == 0)
		{
			std::cout << "Error : division by zero impossible!" << std::endl;
			exit(1);
		}
		return (b / a);
	}
	return 0;
}

bool isNum(char a)
{
	if (a >= '0' && a <= '9')
		return true;
	return false;
}
