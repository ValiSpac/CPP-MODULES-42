# pragma once

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public Form
{
	private:
		PresidentialPardonForm();
		virtual void concreteExec();
	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(PresidentialPardonForm& org);
		PresidentialPardonForm& operator=( PresidentialPardonForm& org);
		virtual ~PresidentialPardonForm();
};
