# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <iostream>
# include <cstdlib>
# include <unistd.h>
# include <typeinfo>

int random_nb(void)
{
	srand(time(NULL));
	return ((rand() % 3) + 1);
}

Base * generate(void)
{
	int nb = random_nb();
	Base *base = NULL;
	try{
	if (nb == 1)
		base = dynamic_cast<Base *>(new A);
	else if (nb == 2)
		base = dynamic_cast<Base *>(new B);
	else if (nb == 3)
		base = dynamic_cast<Base *>(new C);
	return base;}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return NULL;
	}
}

void identify(Base *p)
{
	try
	{
		if (dynamic_cast<A *>(p))
			std::cout << "A" << std::endl;
		else if (dynamic_cast<B *>(p))
			std::cout << "B" << std::endl;
		else if (dynamic_cast<C *>(p))
			std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void identify(Base &p)
{
	try
	{
		Base val = dynamic_cast<A &>(p);
			std::cout << "A" << std::endl;
	}
	catch(std::bad_cast& e){}
	try
	{
		Base val = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
	}
	catch(std::bad_cast& e){}
	try
	{
		Base val = dynamic_cast<C &>(p);
			std::cout << "C" << std::endl;
	}
	catch(std::bad_cast& e){}
}

int main()
{
	Base *p1 = generate();
	usleep(1000000);
	Base *p2 = generate();

	std::cout << "Pointer" << std::endl;
	identify(p1);
	identify(p2);
	std::cout << "Reference" << std::endl;
	identify(*p1);
	identify(*p2);
	delete p1;
	delete p2;
	return 0;
}
