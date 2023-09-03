# include "WrongAnimal.hpp"
# include <iostream>

using std::cout;
using std::endl;

WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal_type";
	cout << "WrongAnimal default constructor called" << endl;
}

WrongAnimal::~WrongAnimal()
{
	cout << "WrongAnimal decunstructor called" << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& org)
{
	this->type = org.type;
	cout << "Copy WrongAnimal constructor called" << endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& org)
{
	this->type = org.type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void	WrongAnimal::makeSound() const
{
	cout << "...Wrong animal noise?????..." << endl;
}
