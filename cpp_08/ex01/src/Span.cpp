#include "Span.hpp"

//  ==========| CONSTRUCTORS |==========
Span::Span() : capacity(0) {}

Span::Span(unsigned int N) : capacity(N) {}

Span::Span(const Span &other)
{
	*this = other;
}

//  ===========| DESTRUCTOR |===========
Span::~Span() {}

//  =======| OPERATOR OVERLOADS |=======
Span &Span::operator=(const Span &rhs)
{
	this->capacity = rhs.capacity;
	this->numbers = rhs.numbers;
}

//  ============| METHODS |=============

void Span::addNumber(int num)
{
	if (this->numbers.size() >= capacity)
		throw SpanFullException();
	this->numbers.push_back(num);
}

int Span::shortestSpan()
{
	// TODO
}

int Span::longestSpan()
{
	// TODO
}

//  ========| VIRTUAL METHODS |=========

const char *Span::SpanFullException::what() const throw()
{
	return "Span is full!";
}
