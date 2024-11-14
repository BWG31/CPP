#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template <class T> void iter(T *array, size_t length, void (*f)(T&))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

#endif