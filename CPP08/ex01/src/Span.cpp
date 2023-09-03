# include "Span.hpp"

Span::Span(unsigned int n)
{
	this->size = n;
}

Span::Span(const Span& ref)
{
	*this = ref;
}

Span::~Span(){}

Span &Span::operator=(const Span& ref)
{
	if (this != &ref)
	{
		this->size = ref.size;
		this->v_ = ref.v_;
	}
	return (*this);
}

void Span::addNumber(int nb)
{
	if (this->v_.size() >= this->size)
		throw fullSpan();
	this->v_.push_back(nb);
}

int Span::shortestSpan()
{
	if (this->v_.size() < 2)
		throw noSpan();
	std::vector<int> vector = this->v_;
	std::sort(vector.begin(), vector.end());
	int min = vector[1] - vector[0];
	for (int i = 0; i < (int)this->getSize(); i++)
	{
		if (vector[i + 1] - vector[i] < min)
			min = vector[i + 1] - vector[i];
	}
	return min;
}

unsigned int Span::getSize()
{
	return this->size;
}

int Span::longestSpan()
{
	if (this->v_.size() < 2)
		throw noSpan();
	std::vector<int> vector = this->v_;
	std::sort(vector.begin(), vector.end());
	return (vector[vector.size() - 1] - vector[0]);
}

void Span::fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator it = begin; it != end; it++)
	{
		this->addNumber(*it);
	}
}

const char* Span::noSpan::what() const throw()
{
	return ("no availabe span");
}

const char* Span::fullSpan::what() const throw()
{
	return ("span full");
}
