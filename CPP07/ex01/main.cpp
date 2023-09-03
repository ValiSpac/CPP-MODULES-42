# include <iostream>
# include "iter.hpp"
# include <cstdlib>

template <typename T>
void print(T &a)
{
	std::cout << a << std::endl;
}

int main()
{
	std::string string[3];
	int nbs[] = {12, 32, 123, 77};
	float f_nbs[] = {43.02f, 32.77f, 123.23451f, 77.0f, 0.001f};

	string[0] = "Hello";
	string[1] = "World";
	string[2] = "Ca va?";

	::iter(string, 3, &print);
	::iter(nbs, 5, &print);
	::iter(f_nbs, 5, &print);
	return 0;
}
