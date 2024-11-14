#ifndef ARRAY_HPP
# define ARRAY_HPP

template <class T> class Array
{
	public:
		Array();
		Array(const Array &other);
		~Array();

		Array &operator=(const Array &rhs);
	private:
		int	_size;
		T	*elements;
};

#include "Array.tpp"

#endif