# include "AForm.hpp"
# include "../inc/Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

using std::endl;
using std::cout;
using std::exception;

void printError(exception& e)
{
	cout << "Error: " << e.what() << endl;
}

int main()
{
	Bureaucrat *parlamentar = new Bureaucrat("parlamentar", 1);
	Form *Shrubbery = new ShrubberyCreationForm("home");

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
	parlamentar->executeForm(*Shrubbery);

	//Shrubbery->execute(*parlamentar);
	delete Shrubbery;


////////////////////////////////////////////////////////////////

	cout << "\n----Robotomy Form----\n" << endl;

	Form *Robot = new RobotomyRequestForm("Robot");
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
	parlamentar->executeForm(*Robot);

	Robot->execute(*parlamentar);
	delete Robot;

////////////////////////////////////////////////////////////////

	cout << "\n----Presidential Pardon Form----\n" << endl;
	Form *President = new PresidentialPardonForm("Convict");
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
	parlamentar->executeForm(*President);

	President->execute(*parlamentar);
	delete President;

	delete parlamentar;
}
