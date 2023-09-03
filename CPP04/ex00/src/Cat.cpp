# include "Cat.hpp"
# include <iostream>

using std::cout;
using std::endl;

Cat::Cat() : Animal()
{
	this->type = "Cat";
	cout << "Cat default constructor called" << endl;
}

Cat::~Cat()
{
	cout << "Cat decunstructor called" << endl;
}

Cat::Cat(const Cat& org): Animal(org)
{
	this->type = org.type;
	cout << "Copy Cat constructor called" << endl;
}

Cat &Cat::operator=(const Cat& org)
{
	this->type = org.type;
	cout << "Cat Copy asignment operator called" << endl;
	return (*this);
}

std::string Cat::getType() const
{
	return (this->type);
}

void	Cat::makeSound() const
{
	cout << "!!!!meow!!!!" << endl;
}
