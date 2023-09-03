# include "RobotomyRequestForm.hpp"
# include <cstdlib>

using std::endl;
using std::cout;

RobotomyRequestForm::RobotomyRequestForm()
	: Form("RobotomyRequestForm", "default", 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: Form("RobotomyRequestForm", target, 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& org)
	: Form("RobotomyRequestForm", org.getTarget(), 72, 45)
{
	*this = org;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm& org)
{
	if (this == &org)
		return (*this);
	*this = org;
	return (*this);
}

void RobotomyRequestForm::concreteExec()
{
	std::srand(time(NULL));
	if (std::rand() % 2)
		cout << "Congratulations Robotomy succeded on " << this->getTarget() << endl;
	else
		cout << "Robotomy failed on " << this->getTarget() << " and might be dead!" << endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){}
