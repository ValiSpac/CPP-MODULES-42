#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const int inInt);
		Fixed(const float inFloat);
		Fixed(const Fixed &to_copy);
		Fixed &operator = (const Fixed &original);
		~Fixed();
		bool	operator>(const Fixed &nbr);
		bool	operator<(const Fixed &nbr);
		bool	operator>=(const Fixed &nbr);
		bool	operator<=(const Fixed &nbr);
		bool	operator==(const Fixed &nbr);
		bool	operator!=(const Fixed &nbr);
		Fixed	operator+(const Fixed &nbr);
		Fixed	operator-(const Fixed &nbr);
		Fixed	operator*(const Fixed &nbr);
		Fixed	operator/(const Fixed &nbr);
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);
		static	Fixed &min(Fixed& a, Fixed &b);
		static	const Fixed &min(const Fixed& a,const Fixed &b);
		static	Fixed &max(Fixed& a, Fixed &b);
		static	const Fixed &max(const Fixed& a,const Fixed &b);
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					fixed_point;
		static const int	fract_bits = 8;
};

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr);

#endif

