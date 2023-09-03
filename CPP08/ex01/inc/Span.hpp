# pragma once

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
	private:
		unsigned int size;
		std::vector<int> v_;
	public:
		Span(unsigned int n);
		Span(const Span& ref);
		Span &operator=(const Span& ref);
		~Span();
		int shortestSpan();
		int longestSpan();
		void addNumber(int nb);
		unsigned int getSize();
		class noSpan : public std::exception {
			virtual const char* what() const throw();
		};
		class fullSpan : public std::exception {
			virtual const char* what() const throw();
		};
		void fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};
