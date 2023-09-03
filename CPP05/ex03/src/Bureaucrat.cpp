# include "../inc/Bureaucrat.hpp"

using std::cout;
using std::endl;

Bureaucrat::Bureaucrat() : _name("unknown") , _grade(150)
{
	cout << "Default constructor for Bureaucrat was created with grade " << this->getGrade() << endl;
}

Bureaucrat::~Bureaucrat()
{
	cout << "Destructor for Bureaucrat called" << endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("unknown")
{
	cout << "Constructor for Bureaucrat was created with grade " << this->getGrade() << endl;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string name) : _name(name) , _grade(150)
{
	cout << "Constructor for Bureaucrat called with name " << name << endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) : _name(ref._name) , _grade(ref._grade)
{
	cout << "Copy constructor for Bureaucrat was called from " << ref._name << endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	cout << "Constructor for " << name << " called with grade " << grade << endl;
	this->setGrade(grade);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& ref)
{
	cout << "Assignment operator called" << endl;
	if (this == &ref)
		return (*this);
	this->_grade = ref.getGrade();
	return (*this);
}

void	Bureaucrat::setGrade(int x)
{
	if (x < 1)
		throw GradeTooHighException();
	else if (x > 150)
		throw GradeTooLowException();
	else
		this->_grade = x;
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

void Bureaucrat::incrementGrade()
{
	this->setGrade(this->getGrade() - 1);
}

void Bureaucrat::decrementGrade()
{
	this->setGrade(this->getGrade() + 1);
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade to low\n");
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade to high\n");
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat &a)
{
	o << "Bureaucrat " << a.getName() << ":\n\tgrade: " << a.getGrade() << endl;
	return (o);
}

void	Bureaucrat::executeForm(Form &form)const
{
	try
	{
			form.execute(*this);
			std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Bureaucrat::signForm(Form& f)
{
	try
	{
		f.beSigned(*this);
		cout << this->getName() << " signs " << f.getName() << endl;
	}
	catch (std::exception& e)
	{
		cout << this->getName() << " cannot sign " << f.getName() << " because "
					<< e.what() << endl;
	}
}
