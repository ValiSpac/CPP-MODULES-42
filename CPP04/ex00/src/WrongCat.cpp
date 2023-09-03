# include "WrongCat.hpp"
# include <iostream>

using std::cout;
using std::endl;

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	cout << "WrongCat default constructor called" << endl;
}

WrongCat::~WrongCat()
{
	cout << "WrongCat decunstructor called" << endl;
}

WrongCat::WrongCat(const WrongCat& org): WrongAnimal(org)
{
	this->type = org.type;
	cout << "Copy WrongCat constructor called" << endl;
}

WrongCat &WrongCat::operator=(const WrongCat& org)
{
	this->type = org.type;
	return (*this);
}

std::string WrongCat::getType() const
{
	return (this->type);
}

void	WrongCat::makeSound() const
{
	cout << "!!!!meow but in a weird way!!!!" << endl;
}
