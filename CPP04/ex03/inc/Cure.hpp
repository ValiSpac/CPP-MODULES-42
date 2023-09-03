# pragma once

# include "ICharacter.hpp"

class Cure : public AMateria
{
private:
	std::string _type;
public:
	Cure();
	Cure(const Cure& ref);
	Cure &operator=(const Cure& ref);
	std::string const & getType() const;
	~Cure();
	Cure* clone() const;
	void use(ICharacter& target);
};
