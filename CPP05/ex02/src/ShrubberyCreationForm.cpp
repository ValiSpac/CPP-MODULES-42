# include "ShrubberyCreationForm.hpp"
# include <string.h>
# include <fstream>

using std::endl;

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("ShrubberyCreationForm", "default", 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: Form("ShrubberyCreationForm", target, 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& org)
	: Form("ShrubberyCreationForm", org.getTarget(), 145, 137)
{
	*this = org;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm& org)
{
	if (this == &org)
		return (*this);
	*this = org;
	return (*this);
}

void ShrubberyCreationForm::concreteExec()
{
	std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());
	for (int i = 0; i < 5; i++)
	{
		outfile <<"           / |    |/        " << endl;
		outfile <<"       |/ / ||/  /_/___/_   " << endl;
		outfile <<"       /   |/ [  ]          " << endl;
		outfile <<"  _(__|_|   |  /_____/_     " << endl;
		outfile <<"         )  | /          /  " << endl;
		outfile <<"__ _-----`  |{,-----------~ " << endl;
		outfile <<"          () }{             " << endl;
		outfile <<"          ()}{{             " << endl;
		outfile <<"           }}{              " << endl;
		outfile <<"           {{}              " << endl;
		outfile <<"     , -=-~{ .-^- _         " << endl;
		outfile <<"---------------------------\n" << endl;
	}
	outfile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}
