#ifndef PRINT_ARRAY_HPP
# define PRINT_ARRAY_HPP

#include <cstddef>
#include <iostream>

template <class T> void print_array(T *array, size_t length)
{
	std::cout << "=== PRINT ARRAY: " << array << " ===\n";
	for (size_t i = 0; i < length; i++)
	{
		std::cout << " [ " << array[i] << " ]";
	}
	std::cout << std::endl;
}

template <> void print_array(char *array, size_t length)
{
	std::cout << "=== PRINT ARRAY: " << &array << " ===\n";
	for (size_t i = 0; i < length; i++)
	{
		std::cout << " [ " << array[i] << " ]";
	}
	std::cout << std::endl;
}

#endif