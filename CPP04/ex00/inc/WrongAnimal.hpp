# pragma once
# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& org);
		WrongAnimal &operator=(const WrongAnimal& org);
		virtual ~WrongAnimal();
		std::string getType() const;
		void makeSound() const;
	protected:
		std::string type;
};
