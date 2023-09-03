# include "Character.hpp"

using std::cout;
using std::endl;

Character::Character(std::string name) : _name(name)
{
	this->inventory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
}

Character::Character(const Character& ref) : _name(ref.getName() + "_DeepCopy")
{
	this->inventory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
	{
		if (ref.inventory[i] != 0)
			this->inventory[i] = (ref.inventory[i])->clone();
		else
			this->inventory[i] = 0;
	}
	cout << this->getName() << " created from " << ref.getName() << endl;
}

Character &Character::operator=(const Character& ref)
{
	this->_name = ref.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		if (ref.inventory[i])
			this->inventory[i] = (ref.inventory[i])->clone();
		else
			this->inventory[i] = 0;
	}
	return (*this);
}

Character::~Character()
{
	cout << this->getName() << " died!" << endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
	delete[] this->inventory;
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	int i = 0;
	if (!m)
	{
		cout << this->getName() << " is not able to equip something that does not exist!" << endl;
		return ;
	}
	while (i < 4 && (this->inventory)[i] != 0)
		i++;
	if (i >= 4)
	{
		cout << this->getName() << "'s inventory is full!" << endl;
		return ;
	}
	cout << this->getName() << " equiped " << m->getType() << " at slot " << i << endl;
	inventory[i] = m->clone();
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		cout << "This inventory slot does not exist!" << endl;
		return ;
	}
	if (this->inventory[idx] == 0)
	{
		cout << "This inventory slot is empty!" << endl;
		return;
	}
	AMateria *ptr = this->inventory[idx];
	cout << this->getName() << " unequiped " << ptr->getType() << " at slot " << idx << endl;
	delete this->inventory[idx];
	this->inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
	{
		cout << "This inventory slot does not exist!" << endl;
		return ;
	}
	if (this->inventory[idx] == 0)
	{
		cout << "This inventory slot is empty!" << endl;
		return;
	}
	cout << this->getName();
	(this->inventory[idx])->use(target);
}

AMateria *Character::getInventory(int idx)
{
	return(this->inventory[idx]);
}
