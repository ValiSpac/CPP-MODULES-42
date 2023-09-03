# include "../inc/Cat.hpp"
# include <iostream>

using std::cout;
using std::endl;

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	cout << "Cat default constructor called" << endl;
}

Cat::~Cat()
{
	delete this->brain;
	cout << "Cat decunstructor called" << endl;
}

Cat::Cat(const Cat& org): Animal(org)
{
	this->type = org.getType();
	this->brain = new Brain(*(org.brain));
	cout << "Cat Copy constructor called" << endl;
}

Cat &Cat::operator=(const Cat& org)
{
	this->type = org.getType();
	this->brain = org.brain;
	cout << "Cat Copy asignment operator called" << endl;
	return (*this);
}

std::string Cat::getType() const
{
	return (this->type);
}

Brain Cat::getBrain() const
{
	return (*this->brain);
}

void	Cat::makeSound() const
{
	cout << "!!!!meow!!!!" << endl;
}
