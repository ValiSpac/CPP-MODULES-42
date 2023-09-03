# include "Form.hpp"
# include "inc/Bureaucrat.hpp"

using std::cout;
using std::endl;
using std::exception;

void	printError(exception& e) {
	cout << "Error: " << e.what() << endl;
}

int	main() {
	Bureaucrat	burro("burro", 42);
	cout << burro;

	cout << "\nconstructor\n" << endl;
	try {
		Form	formaccio("formaccio", 1000, 150);
	}
	catch (exception& e) {
		printError(e);
	}
	try {
		Form	formaccio("formaccio", 42, 1);
	}
	catch (exception& e) {
		printError(e);
	}

	try {
		Form	formino("formino", 42, 20);
		Form	formone("formone", 1, 50);

		cout << endl << formino << formone;

		burro.signForm(formino);
		cout << formino;
		burro.signForm(formino);
		burro.signForm(formone);
		for (int i = 0;i <= 40; i++)
			burro.incrementGrade();
		burro.signForm(formone);
		cout << formone;
	}
	catch (exception& e) {
		printError(e);
	}
}
