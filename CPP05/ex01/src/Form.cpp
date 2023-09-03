# include "Form.hpp"

using std::cout;
using std::endl;

Form::Form() : _name("unknown") , _grade(150), _signed(false), exec_grade(150)
{
	cout << "Default constructor for Form was created with grade " << this->getGrade() << endl;
}

Form::~Form()
{
	cout << "Destructor for Form called" << endl;
}

Form::Form(const Form& ref) : _name(ref._name) , _grade(ref._grade), _signed(ref._signed), exec_grade(ref.exec_grade)
{
	cout << "Copy constructor for Form was called from " << ref._name << endl;
}

Form::Form(const std::string name, int grade, int execgrade) : _name(name), _signed(false), exec_grade(execgrade)
{
	cout << "Constructor for " << name << " called with grade " << grade << endl;
	this->setGrade(grade);
}

Form &Form::operator=(const Form& ref)
{
	cout << "Assignment operator called " << endl;
	if (this == &ref)
		return (*this);
	this->exec_grade = ref.getExecGrade();
	this->_signed = ref.isSigned();
	this->_grade = ref.getGrade();
	return (*this);
}

int Form::getExecGrade() const
{
	return(this->exec_grade);
}

bool Form::isSigned() const
{
	if (this->_signed == false)
		return (false);
	else
		return (true);
}

void Form::beSigned(Bureaucrat& a)
{
	if (this->isSigned() == true)
		throw Form::SignedFormException();
	else if (a.getGrade() <= this->getGrade())
		this->_signed = true;
	else if (a.getGrade() >= this->getGrade())
		throw Form::GradeTooLowException();
	else
		throw Form::GradeTooHighException();
}

void	Form::setGrade(int x)
{
	if (x < 1)
		throw GradeTooHighException();
	else if (x > 150)
		throw GradeTooLowException();
	else
		this->_grade = x;
}

int Form::getGrade() const
{
	return (this->_grade);
}

std::string Form::getName() const
{
	return (this->_name);
}

void Form::incrementGrade()
{
	this->setGrade(this->getGrade() - 1);
}

void Form::decrementGrade()
{
	this->setGrade(this->getGrade() + 1);
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade to low\n");
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade to high\n");
}

const char*	Form::SignedFormException::what() const throw()
{
	return ("Form allready signed\n");
}

std::ostream	&operator<<(std::ostream &o, Form &a)
{
	o << "Form " << a.getName() << ":\n\tsigned: ";
	if (a.isSigned() == false)
		o << "false" << endl;
	else
		o << "true" << endl;
	o << "Grade required to execute:" << a.getExecGrade() << std::endl;
	o << "Grade required to sign:" << a.getGrade() << std::endl;
	return (o);
}

