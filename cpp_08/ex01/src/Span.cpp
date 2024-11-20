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
	return (*this);
}

std::ostream &operator<<(std::ostream &os, Span &rhs)
{
	os << "[ SPAN ] :";
	if (rhs.getNumbers().size() == 0)
		os << " empty";
	else
	{
		for (unsigned int i = 0; i < rhs.getNumbers().size(); ++i)
			os << " " << rhs.getNumAt(i);
	}
	os << std::endl;
	return os;
}

//  ============| METHODS |=============

void Span::addNumber(int num)
{
	if (this->numbers.size() >= capacity)
		throw SpanFullException();
	this->numbers.push_back(num);
}

int Span::shortestSpan() const
{
	if (this->numbers.size() < 2)
		throw NotEnoughValuesException();
	std::vector<int> tmp(numbers);
	std::sort(tmp.begin(), tmp.end());
	int	shortest = std::numeric_limits<int>::max();
	for (std::vector<int>::iterator it = tmp.begin();
		it != tmp.end() - 1; ++it)
	{
		if (it[1] - it[0] < shortest)
			shortest = it[1] - it[0];
	}
	return shortest;
}

int Span::longestSpan() const
{
	if (this->numbers.size() < 2)
		throw NotEnoughValuesException();
	std::vector<int> tmp(numbers);
	std::sort(tmp.begin(), tmp.end());
	return (tmp.back() - tmp.front());
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	try
	{
		for (; begin != end; ++begin)
			this->addNumber(*begin);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
}

std::vector<int> Span::getNumbers()
{
	return numbers;
}

int Span::getNumAt(unsigned int index) const
{
	return numbers[index];
}

//  ========| VIRTUAL METHODS |=========

const char *Span::SpanFullException::what() const throw()
{
	return "Span is full!";
}

const char *Span::NotEnoughValuesException::what() const throw()
{
	return "Not enough values to perform operation";
}
