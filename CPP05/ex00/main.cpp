#include "Bureaucrat.hpp"

using std::cout;
using std::endl;
using std::exception;

int	main() {
	cout << "constructor\n" << endl;

	try {
		Bureaucrat	first("first", 1);
		cout << first;
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
	}

	try {
		Bureaucrat	second("second", -42);
		cout << second;
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
	}


	try {
		Bureaucrat	second("second", 4242);
		cout << second;
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
	}

	cout << "increment\n" << endl;

	try {
		Bureaucrat	first("first", 12);
		cout << first;
		first.incrementGrade();
		cout << first;
		first.incrementGrade();
		cout << first;
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
	}

	cout << "decrement\n" << endl;

	try {
		Bureaucrat	first("first", 139);
		cout << first;
		first.decrementGrade();
		cout << first;
		for (int i = 0; i < 11; i++)
			first.decrementGrade();
		cout << first;
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
	}
}
