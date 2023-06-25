#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &to_copy);
		Fixed &operator = (const Fixed&original);
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
	private:
		int					fixed_point;
		static const int	fract_bits = 8;
};

#endif
