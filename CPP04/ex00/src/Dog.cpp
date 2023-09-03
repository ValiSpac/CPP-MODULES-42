# include "Dog.hpp"
# include <iostream>

using std::cout;
using std::endl;

Dog::Dog() : Animal()
{
	this->type = "Dog";
	cout << "Dog default constructor called" << endl;
}

Dog::~Dog()
{
	cout << "Dog decunstructor called" << endl;
}

Dog::Dog(const Dog& org): Animal(org)
{
	this->type = org.type;
	cout << "Copy Dog constructor called" << endl;
}

Dog &Dog::operator=(const Dog& org)
{
	this->type = org.type;
	cout << "Dog Copy asignment operator called" << endl;
	return (*this);
}

std::string Dog::getType() const
{
	return (this->type);
}

void	Dog::makeSound() const
{
	cout << "~~~Ham Ham~~~" << endl;
}
