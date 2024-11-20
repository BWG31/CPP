#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
# include <algorithm>
# include <limits>
# include <iostream>
# include <iomanip>

class Span
{
	public:
		Span();
		Span(const Span &other);
		Span(unsigned int N);
		~Span();

		Span &operator=(const Span &rhs);

		void	addNumber(int num);
		int		shortestSpan() const;
		int		longestSpan() const;
		void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		getNumAt(unsigned int index) const;
		std::vector<int>	getNumbers();

	private:
		unsigned int 		capacity;
		std::vector<int> 	numbers;

		class SpanFullException;
		class NotEnoughValuesException;
};

std::ostream &operator<<(std::ostream &os, Span &rhs);

class Span::SpanFullException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class Span::NotEnoughValuesException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

#endif