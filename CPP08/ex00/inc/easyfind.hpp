# pragma once

# include <iostream>
# include <algorithm>

class InvalidArg : public std::exception
{
	public:
		const char *what() const throw(){return("Invalid argument");};
};

template<typename T>
int easyfind(T &container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw InvalidArg();
	return *it;
}

