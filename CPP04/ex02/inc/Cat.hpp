# pragma once

# include "AAnimal.hpp"
# include <iostream>
# include "Brain.hpp"

class Cat : virtual public Animal
{
	public:
		Cat();
		Cat(const Cat& org);
		Cat &operator=(const Cat& org);
		virtual ~Cat();
		std::string getType() const;
		void	makeSound() const;
		Brain getBrain() const;
	private:
		Brain *brain;
		std::string type;
};
