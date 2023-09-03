# include "../inc/Dog.hpp"
# include <iostream>

using std::cout;
using std::endl;

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	cout << "Dog default constructor called" << endl;
}

Dog::~Dog()
{
	delete this->brain;
	cout << "Dog decunstructor called" << endl;
}

Dog::Dog(const Dog& org): Animal(org)
{
	this->type = org.getType();
	this->brain = new Brain(*(org.brain));
	cout << "Copy Dog constructor called" << endl;
}

Dog &Dog::operator=(const Dog& org)
{
	this->type = org.getType();
	this->brain = org.brain;
	cout << "Dog Copy asignment operator called" << endl;
	return (*this);
}

std::string Dog::getType() const
{
	return (this->type);
}

Brain Dog::getBrain() const
{
	return (*this->brain);
}

void	Dog::makeSound() const
{
	cout << "~~~Ham Ham~~~" << endl;
}
