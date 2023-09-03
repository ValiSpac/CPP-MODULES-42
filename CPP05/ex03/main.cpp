# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

using std::endl;
using std::cout;
using std::exception;

void printError(exception& e)
{
	cout << "Error: " << e.what() << endl;
}

int main()
{
	Intern copil;
	Bureaucrat *parlamentar = new Bureaucrat("parlamentar", 1);
	Form *Shrubbery = copil.makeForm("ShrubberyCreationForm", "home");

	cout << "\n----Shrubbery Form----\n" << endl;

	try
	{
	Bureaucrat prost("prost", 150);
	prost.signForm(*Shrubbery);
	}
	catch (exception& e)
	{
		printError(e);
	}

	Shrubbery->beSigned(*parlamentar);
	parlamentar->signForm(*Shrubbery);

	Shrubbery->execute(*parlamentar);
	delete Shrubbery;


////////////////////////////////////////////////////////////////

	cout << "\n----Robotomy Form----\n" << endl;

	Form *Robot = copil.makeForm("RobotomyRequestForm", "Robot");
	try
	{
	Bureaucrat prost("prost", 87);
	prost.signForm(*Robot);
	}
	catch (exception& e)
	{
		printError(e);
	}
	Robot->beSigned(*parlamentar);
	parlamentar->signForm(*Robot);

	Robot->execute(*parlamentar);
	delete Robot;

////////////////////////////////////////////////////////////////

	cout << "\n----Presidential Pardon Form----\n" << endl;
	Form *President = copil.makeForm("PresidentialPardonForm", "Convict");
	try
	{
	Bureaucrat pic("pic", 5);
	pic.signForm(*President);
	pic.signForm(*President);
	}
	catch (exception& e)
	{
		printError(e);
	}
	parlamentar->signForm(*President);

	President->execute(*parlamentar);
	delete President;

	cout << endl;
	Form *pic = copil.makeForm("pic", "home");
	Form *poc = copil.makeForm("poc", "home");

	(void)pic;
	(void)poc;
	delete parlamentar;
}

