# pragma once

# include "Animal.hpp"
# include <iostream>

class Cat : virtual public Animal
{
	public:
		Cat();
		Cat(const Cat& org);
		Cat &operator=(const Cat& org);
		~Cat();
		std::string getType() const;
		void	makeSound() const;
	private:
		std::string type;
};
