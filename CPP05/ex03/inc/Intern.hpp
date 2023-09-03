# pragma once

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& ref);
		Intern &operator=(const Intern& ref);
		Form* makeForm(const std::string from,const std::string target);
		~Intern();
};
