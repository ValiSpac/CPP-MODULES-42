# pragma once

# include <iostream>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria** materials;
public:
	MateriaSource();
	MateriaSource(const MateriaSource& ref);
	MateriaSource &operator=(const MateriaSource& ref);
	virtual ~MateriaSource();
	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);
};
