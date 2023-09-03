# pragma once

# include "ICharacter.hpp"

class Ice : public AMateria
{
private:
	std::string _type;
public:
	Ice();
	Ice(const Ice& ref);
	Ice &operator=(const Ice& ref);
	std::string const & getType() const;
	~Ice();
	Ice* clone() const;
	void use(ICharacter& target);
};
