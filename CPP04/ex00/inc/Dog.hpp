# pragma once

# include "Animal.hpp"
# include <iostream>

class Dog : virtual public Animal
{
	public:
		Dog();
		Dog(const Dog& org);
		Dog &operator=(const Dog& org);
		~Dog();
		std::string getType() const;
		void	makeSound() const;
	private:
		std::string type;
};
