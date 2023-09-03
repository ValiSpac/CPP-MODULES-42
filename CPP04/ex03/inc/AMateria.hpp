# pragma once

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	const std::string _type;
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(AMateria const & ref);
	 AMateria &operator=(AMateria const & ref);
	virtual ~AMateria();
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
