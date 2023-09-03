# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: Form("PresidentialPardonForm", "default", 25, 5){}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: Form("PresidentialPardonForm", target, 25, 5){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& org)
	: Form("PresidentialPardonForm", org.getTarget(), 25, 5)
{
	*this = org;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm& org)
{
	if (this == &org)
		return (*this);
	*this = org;
	return (*this);
}

void PresidentialPardonForm::concreteExec()
{
	std::cout << this->getTarget() << " got pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){}
