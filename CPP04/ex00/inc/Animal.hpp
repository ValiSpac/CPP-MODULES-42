# pragma once

# include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal& org);
		Animal &operator=(const Animal& org);
		virtual ~Animal();
		std::string getType() const;
		virtual void makeSound() const;
	protected:
		std::string type;
};
