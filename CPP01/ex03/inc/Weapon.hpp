# ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	public:
		Weapon(std::string type);
		void	setType(std::string type);
		const std::string&	getType(void) const;
	private:
		std::string	type;
};

# endif
