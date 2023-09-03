# include "MateriaSource.hpp"

using std::cout;
using std::endl;

MateriaSource::MateriaSource()
{
	this->materials = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->materials[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& ref)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->materials[i])
			this->materials[i] = (ref.materials[i])->clone();
		else
			this->materials[i] = 0;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource& ref)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materials[i])
			delete this->materials[i];
		if (ref.materials[i])
			this->materials[i] = (ref.materials[i])->clone();
		else
			this->materials[i] = 0;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materials[i] != 0)
			delete this->materials[i];
	}
	delete[] this->materials;
}

void	MateriaSource::learnMateria(AMateria* m)
{
	int i = 0;
	while(i < 4 && (this->materials)[i] != 0)
		i++;
	if (i >= 4)
	{
		delete m;
		cout << "Can't learn more materias!" << endl;
		return ;
	}
	(this->materials)[i] = m;
	cout << "Learned materia " << (this->materials)[i]->getType() << endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	if (!this->materials[i])
	{
		cout << "there are no materias learned!" << endl;
		return 0;
	}
	while (i < 4 && this->materials[i] && ((this->materials[i])->getType()) != type)
		i++;
	if (i >= 4)
	{
		cout << "There is no materia of type " << type << endl;
		return 0;
	}
	return (this->materials[i]);
}
