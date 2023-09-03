# pragma once

# include "AForm.hpp"
# include <iostream>

class RobotomyRequestForm : public Form
{
	private:
		RobotomyRequestForm();
		virtual void concreteExec();
	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(RobotomyRequestForm& org);
		RobotomyRequestForm& operator=( RobotomyRequestForm& org);
		virtual ~RobotomyRequestForm();
};
