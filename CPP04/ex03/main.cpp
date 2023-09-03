# include "Character.hpp"
# include "Cure.hpp"
# include "Ice.hpp"
# include "MateriaSource.hpp"

int main()
{
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
src->learnMateria(new Ice());
src->learnMateria(new Cure());
src->learnMateria(new Ice());
src->learnMateria(new Cure());

ICharacter* me = new Character("me");

AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
tmp = src->createMateria("ice");
me->equip(tmp);

ICharacter* bob = new Character("bob");

me->use(0, *bob);
me->use(1, *bob);
me->use(2, *bob);
me->unequip(0);
me->unequip(0);
me->use(0, *bob);
tmp = src->createMateria("ice");
me->equip(tmp);
me->use(0, *bob);

std::cout << "\ncopy test" << std::endl << std::endl;

Character *character = new Character("character");
tmp = src->createMateria("cure");
character->equip(tmp);
tmp = src->createMateria("ice");
character->equip(tmp);
tmp = src->createMateria("cure");
character->equip(tmp);

ICharacter* man = new Character(*character);

delete character;

tmp = src->createMateria("cure");
man->equip(tmp);
tmp = src->createMateria("ice");
man->equip(tmp);
tmp = src->createMateria("cure");
man->equip(tmp);

man->use(1, *bob);
man->use(2, *bob);
man->unequip(1);
man->use(3, *bob);;
IMateriaSource* rrc = new MateriaSource();
IMateriaSource* trc = new MateriaSource();
IMateriaSource* yrc = new MateriaSource();

delete man;
delete me;
delete bob;
delete yrc;
delete trc;
delete rrc;
delete src;
return 0;
}
