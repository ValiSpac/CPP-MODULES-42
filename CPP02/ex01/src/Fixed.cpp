# include <iostream>
# include <cstring>
# include <cmath>
# include "../inc/Fixed.hpp"

using std::cout;
using std::endl;

Fixed::Fixed() : fixed_point(0)
{
	cout << "Constructor called" << endl;
}

Fixed::Fixed(const int inInt) : fixed_point(inInt * (1 << Fixed::fract_bits))
{
	cout << "Int constructor called" << endl;
}

Fixed::Fixed(const float inFloat) : fixed_point(roundf(inFloat * (1 << Fixed::fract_bits)))
{
	cout << "Float constructor called" << endl;
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

float	Fixed::toFloat(void) const
{
	return (float)this->fixed_point / (float)(1 << Fixed::fract_bits);
}

int		Fixed::toInt(void) const
{
	return this->fixed_point >> Fixed::fract_bits;
}

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr)
{
	stream << nbr.toFloat();
	return stream;
}
