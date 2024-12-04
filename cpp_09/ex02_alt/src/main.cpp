#include "PmergeMe.hpp"
#include <exception>
#include <iostream>
#include <cmath>

// main helpers
bool validate_input(int_vector &input, int argc, char **argv);
void print_vector(int_vector &input);

int main(int argc, char **argv)
{
	int_vector input;
	if (!validate_input(input, argc, argv))
		return 1;
	std::cout << "Before:\t";
	print_vector(input);

	PmergeMe(input, 1);

	std::cout << "After:\t";
	print_vector(input);

	for (size_t i = 1; i < 10; ++i)
		std::cout << getNumsToInsert(i, input) << std::endl;

	return 0;
}
