# include "Brain.hpp"
# include <sstream>

using std::cout;
using std::endl;

Brain::Brain()
{
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = "Thoughts........";
		std::stringstream stream;
		stream << i;
		this->ideas[i] += stream.str();
	}
	cout << "Brain Default constructor called" << endl;
}

Brain::Brain(const Brain& org)
{
	std::string *ref = org.getIdeas();
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ref[i];
	cout << "Brain Copy constructor called" << endl;
}

Brain &Brain::operator=(const Brain& org)
{
	std::string *ref = org.getIdeas();
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ref[i];
	cout << "Brain Copy assignment operator called" << endl;
	return (*this);
}

std::string *Brain::getIdeas() const
{
	return (this->ideas);
}

Brain::~Brain()
{
	delete[] this->ideas;
	cout << "Brain deconstructor callled" << endl;
}
