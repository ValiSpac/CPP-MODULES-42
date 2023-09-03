# pragma once

# include "AForm.hpp"
# include <iostream>

class ShrubberyCreationForm : public Form
{
	private:
		ShrubberyCreationForm();
		virtual void concreteExec();
	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(ShrubberyCreationForm& org);
		ShrubberyCreationForm& operator=( ShrubberyCreationForm& org);
		virtual ~ShrubberyCreationForm();
};
