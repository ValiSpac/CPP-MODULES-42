# include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& ref)
{
	*this = ref;
}

Intern &Intern::operator=(const Intern& ref)
{
	if (this == &ref)
		return (*this);
	return (*this);
}

Intern::~Intern(){}

Form *makePresident(const std::string trg)
{
	return (new PresidentialPardonForm(trg));
}

Form *makeShrubbery(const std::string trg)
{
	return (new ShrubberyCreationForm(trg));
}

Form *makeRobot(const std::string trg)
{
	return (new RobotomyRequestForm(trg));
}

Form *Intern::makeForm(const std::string form, const std::string target)
{
	Form *(*form_list[])(const std::string trg) = {&makePresident, &makeShrubbery, &makeRobot};
	std::string forms[] = {"PresidentialPardonForm", "ShrubberyCreationForm", "RobotomyRequestForm"};
	for (int i = 0; i < 3; i++)
	{
		if (form == forms[i])
		{
			std::cout << "Internn created the form: " << form << std::endl;
			return (form_list[i](target));
		}
	}
	std::cout << "Intern couldn't create form: " << form << std::endl;
	return (NULL);
}
