# pragma once

# include <iostream>
# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>(){};
	MutantStack(const MutantStack& ref) : std::stack<T>(ref){};
	virtual ~MutantStack(){};
	typedef typename std::deque<T>::iterator iterator;
	iterator begin(){return this->c.begin();}
	iterator end(){return this->c.end();};
};

