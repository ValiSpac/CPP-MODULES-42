# include <iostream>
# include <cstring>
# include <cmath>
# include "../inc/Fixed.hpp"

using std::cout;
using std::endl;

Fixed::Fixed() : fixed_point(0)
{
}

Fixed::Fixed(const int inInt) : fixed_point(inInt * (1 << Fixed::fract_bits))
{
}

Fixed::Fixed(const float inFloat) : fixed_point(roundf(inFloat * (1 << Fixed::fract_bits)))
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &to_copy)
{
	std::memcpy(this, &to_copy, sizeof(Fixed));
}

Fixed &Fixed::operator = (const Fixed& original)
{
	this->setRawBits(original.getRawBits());
	return *this;
}

int	Fixed::getRawBits(void) const
{
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

bool	Fixed::operator>(const Fixed &nbr)
{
	return this->fixed_point > nbr.getRawBits();
}

bool	Fixed::operator<(const Fixed &nbr)
{
	return this->fixed_point < nbr.getRawBits();
}

bool	Fixed::operator>=(const Fixed &nbr)
{
	return this->fixed_point >= nbr.getRawBits();
}

bool	Fixed::operator<=(const Fixed &nbr)
{
	return this->fixed_point <= nbr.getRawBits();
}

bool	Fixed::operator==(const Fixed &nbr)
{
	return this->fixed_point == nbr.getRawBits();
}

bool	Fixed::operator!=(const Fixed &nbr)
{
	return this->fixed_point != nbr.getRawBits();
}

Fixed	Fixed::operator+(const Fixed &nbr)
{
	return Fixed(this->toFloat() + nbr.toFloat());
}

Fixed	Fixed::operator-(const Fixed &nbr)
{
	return Fixed(this->toFloat() - nbr.toFloat());}

Fixed	Fixed::operator*(const Fixed &nbr)
{
	return Fixed(this->toFloat() * nbr.toFloat());}

Fixed	Fixed::operator/(const Fixed &nbr)
{
	return Fixed(this->toFloat() / nbr.toFloat());
}

Fixed	&Fixed::operator++(void)
{
	this->fixed_point += 1;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(this->fixed_point * toFloat());
	this->fixed_point +=1;
	return tmp;
}

Fixed	&Fixed::operator--(void)
{
	this->fixed_point -= 1;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(this->fixed_point * toFloat());
	this->fixed_point -=1;
	return tmp;
}

Fixed &Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return b;
	return a;
}

const Fixed &Fixed::min(const Fixed& a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return b;
	return a;
}


Fixed &Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return b;
	return a;
}

const Fixed &Fixed::max(const Fixed& a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return b;
	return a;
}
