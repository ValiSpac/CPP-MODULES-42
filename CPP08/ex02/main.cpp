# include "MutantStack.hpp"

int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
std::cout << mstack.top() << std::endl << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (ite != it)
{
--ite;
std::cout << *ite << std::endl;
mstack.pop();
}
std::cout << std::endl << mstack.size() << std::endl;
std::stack<int> s(mstack);
return 0;
}

