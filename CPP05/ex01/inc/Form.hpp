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
		void setGrade(int x);
	public:
		Form();
		~Form();
		Form(const std::string name, int grade, int execgrade);
		Form(const Form& ref);
		Form &operator=(const Form& ref);
		std::string getName() const;
		int getExecGrade() const;
		int	getGrade() const;
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
};

std::ostream	&operator<<(std::ostream &o, Form& a);
