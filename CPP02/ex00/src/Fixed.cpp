# include <iostream>
# include <cstring>
# include "Fixed.hpp"

using std::cout;
using std::endl;

Fixed::Fixed() : fixed_point(0)
{
	cout << "Constructor called" << endl;
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

Fixed::Fixed(const Fixed &to_copy)
{
	cout << "Copy constructor called" << endl;
	//*this = to_copy;
	std::memcpy(this, &to_copy, sizeof(Fixed));
}

Fixed &Fixed::operator = (const Fixed& original)
{
	cout << "Copy assignment operator called" << endl;
	this->setRawBits(original.getRawBits());
	return *this;
}

int	Fixed::getRawBits(void) const
{
	cout << "Function getRawBits() called" << endl;
	return this->fixed_point;
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point = raw;
}

