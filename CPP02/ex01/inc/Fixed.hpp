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
		Fixed &operator = (const Fixed&original);
		~Fixed();
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
