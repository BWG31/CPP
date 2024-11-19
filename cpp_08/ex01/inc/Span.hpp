#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>

class Span
{
	public:
		Span();
		Span(const Span &other);
		Span(unsigned int N);
		~Span();

		Span &operator=(const Span &rhs);

		void	addNumber(int num);
		int		shortestSpan();
		int		longestSpan();

	private:
		unsigned int 		capacity;
		std::vector<int> 	numbers;

		class SpanFullException;
};

class Span::SpanFullException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

#endif