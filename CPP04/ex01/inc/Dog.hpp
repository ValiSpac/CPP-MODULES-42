# pragma once

# include "Animal.hpp"
# include <iostream>
# include "Brain.hpp"

class Dog : virtual public Animal
{
	public:
		Dog();
		Dog(const Dog& org);
		Dog &operator=(const Dog& org);
		virtual ~Dog();
		std::string getType() const;
		void makeSound() const;
		Brain getBrain() const;
	private:
		Brain *brain;
		std::string type;
};
