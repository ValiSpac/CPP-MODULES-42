# include "AAnimal.hpp"
# include "Brain.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

using std::cout;
using std::endl;

int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();
const Animal*(ar[4]);
for (int i = 0; i < 2; i++)
	ar[i] = new Dog();
for (int i = 2; i < 4; i++)
	ar[i] = new Cat();
for (int i = 0; i < 4; i++)
	delete ar[i];
cout << endl;
Dog dog;
Dog& ref_dog(dog);
Brain brain1 = dog.getBrain();
Brain brain2 = ref_dog.getBrain();
cout << "~~~~~Comparing~~~~~" << endl;
for (int i = 0; i < 21; i++)
	cout << (brain1.getIdeas())[i] << "==========" << (brain2.getIdeas())[i] << endl;
//Animal animal; //test for abstract class - compile error
delete j;//should not create a leak
delete i;
return 0;
}
