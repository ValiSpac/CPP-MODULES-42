# pragma once

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		int _grade;
		bool _signed;
		int exec_grade;
		const std::string _target;
		void setGrade(int x);
	public:
		Form();
		virtual ~Form();
		Form(const std::string name, const std::string target,int grade, int execgrade);
		Form(const Form& ref);
		Form &operator=(const Form& ref);
		std::string getName() const;
		int getExecGrade() const;
		int	getGrade() const;
		std::string getTarget() const;
		void beSigned(Bureaucrat& a);
		bool isSigned() const;
		void incrementGrade();
		void decrementGrade();
		class GradeTooLowException: public std::exception {
			virtual const char*	what() const throw();
		};

		class GradeTooHighException: public std::exception {
			virtual const char*	what() const throw();
		};

		class SignedFormException: public std::exception {
			virtual const char*	what() const throw();
		};

		class UnsignedFormException: public std::exception {
			virtual const char*	what() const throw();
		};
		void execute(Bureaucrat const & executor);
		virtual void concreteExec() = 0;
};

std::ostream	&operator<<(std::ostream &o, Form& a);
