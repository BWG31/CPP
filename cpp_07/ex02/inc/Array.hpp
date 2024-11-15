#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>
#include <iostream>
#include <stdexcept>

template <class T> class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T> &other);
		~Array();

		Array<T> &operator=(const Array &rhs);
		T &operator[](size_t index);
		const T &operator[](size_t index) const;

		size_t	size() const;
	private:
		size_t	_size;
		T		*_elements;
};

template <class T>
std::ostream &operator<<(std::ostream &os, const Array<T> &rhs);

#include "Array.tpp"

#endif