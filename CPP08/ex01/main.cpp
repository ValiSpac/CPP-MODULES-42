# include "Span.hpp"

int main()
{
	try
	{
	Span sp(10);
	sp.addNumber(-42);
	sp.addNumber(30);
	sp.addNumber(12);
	sp.addNumber(31);

	std::cout << "initial size = " << sp.getSize() << std::endl;

	std::vector<int> v;
	v.push_back(-5);
	v.push_back(42);
	v.push_back(12);
	v.push_back(13);
	v.push_back(200);
	sp.fillSpan(v.begin(), v.end());

	std::cout << "shortest span = " << sp.shortestSpan() << std::endl;
	std::cout << "longest span = " << sp.longestSpan() << std::endl;
	sp.fillSpan(v.begin(), v.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Span span(1);
		std::cout << span.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
