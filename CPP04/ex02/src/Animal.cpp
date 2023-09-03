# include "AAnimal.hpp"
# include <iostream>

using std::cout;
using std::endl;

Animal::Animal()
{
	this->type = "Animal_type";
	cout << "Animal default constructor called" << endl;
}

Animal::~Animal()
{
	cout << "Animal decunstructor called" << endl;
}

Animal::Animal(const Animal& org)
{
	this->type = org.getType();
	cout << "Copy Animal constructor called" << endl;
}

Animal &Animal::operator=(const Animal& org)
{
	this->type = org.getType();
	cout << "Animal Copy asignment operator called" << endl;
	return (*this);
}

std::string Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	cout << "...animal noise?..." << endl;
}
