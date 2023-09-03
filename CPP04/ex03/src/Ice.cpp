# include "Ice.hpp"

Ice::Ice() : AMateria("ice"){}

Ice::Ice(const Ice& ref) : AMateria(ref.getType()){}

Ice::~Ice(){}

Ice &Ice::operator=(const Ice& ref)
{
	if (this == &ref)
		return (*this);
	this->_type = ref.getType();
	return (*this);
}

std::string const &Ice::getType() const
{
	return (this->_type);
}

Ice* Ice::clone() const
{
	Ice *ret = new Ice();
	return ret;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
