# pragma once

# include <iostream>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
		void setGrade(int x);
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(int grade);
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& ref);
		Bureaucrat &operator=(const Bureaucrat& ref);
		std::string getName() const;
		int	getGrade() const;
		void incrementGrade();
		void decrementGrade();
		class GradeTooLowException: public std::exception {
			virtual const char*	what() const throw();
		};

		class GradeTooHighException: public std::exception {
			virtual const char*	what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat& a);
