# include "Cure.hpp"

Cure::Cure() : AMateria("cure"){}

Cure::Cure(const Cure& ref) : AMateria(ref.getType()){}

Cure::~Cure(){}

Cure &Cure::operator=(const Cure& ref)
{
	if (this == &ref)
		return (*this);
	this->_type = ref.getType();
	return (*this);
}

std::string const &Cure::getType() const
{
	return (this->_type);
}

Cure* Cure::clone() const
{
	Cure *ret = new Cure();
	return ret;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}
