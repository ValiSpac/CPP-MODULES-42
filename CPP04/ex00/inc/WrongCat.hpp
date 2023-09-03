# pragma once

# include "WrongAnimal.hpp"
# include <iostream>

class WrongCat : virtual public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& org);
		WrongCat &operator=(const WrongCat& org);
		~WrongCat();
		std::string getType() const;
		//using a non virtual method it will decide at copile
		void	makeSound() const;
	private:
		std::string type;
};
