# include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: invalid argument!" << std::endl;
		return (1);
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
			rpn.push(operation(a, b, argv[1][i]));
		}
		else if (isNum(argv[1][i]))
			rpn.push(argv[1][i] - 48);
		else if (argv[1][i] != ' ')
		{
			std::cout << "Error" << std::endl;
			return (1);
		}
	}
	std::cout << rpn.top() << std::endl;
}
