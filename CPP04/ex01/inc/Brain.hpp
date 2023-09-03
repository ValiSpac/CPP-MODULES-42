# pragma once

# include <iostream>

class Brain
{
private:
	std::string *ideas;
public:
	Brain();
	Brain(const Brain& org);
	Brain &operator=(const Brain& org);
	std::string *getIdeas() const;
	~Brain();
};
