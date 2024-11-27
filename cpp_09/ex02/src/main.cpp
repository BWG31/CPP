#include "PmergeMe.hpp"
#include <exception>
#include <iostream>

// main helpers
bool validate_input(int_vector &input, int argc, char **argv);
void display_before(int_vector &input);

int main(int argc, char **argv)
{
	int_vector input;
	if (!validate_input(input, argc, argv))
		return 1;
	display_before(input);

	PmergeMe v(input);
	std::cout << v;
	v.sort();
	std::cout << v;
	return 0;
}
