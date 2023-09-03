# pragma once

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	AMateria** inventory;
	std::string _name;
public:
	Character(std::string name);
	Character(const Character& ref);
	Character &operator=(const Character& ref);
	~Character();
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	AMateria *getInventory(int idx);
};
