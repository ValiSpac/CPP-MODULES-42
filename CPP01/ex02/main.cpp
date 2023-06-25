# include <iostream>

using std::string;
using std::cout;
using std::endl;

int main(void)
{
	string	brain = "HI THIS IS BRAIN";
	string	*brainPTR = &brain;
	string	&brainREF = brain;

	cout << "The memory address of the string variable:" << &brain << endl;
	cout << "The memory address held by stringPTR:" << brainPTR << endl;
	cout << "The memory address held by stringREF:" << &brainREF << endl;

	cout << "The value of the string variable:" << brain << endl;
	cout << "The value pointed to by stringPTR:" << *brainPTR << endl;
	cout << "The value pointed to by stringREF:" << brainREF << endl;

	return 0;
}
