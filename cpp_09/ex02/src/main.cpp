#include "PmergeMe.hpp"
#include <iostream>

// main helpers
bool validate_input(int_vector &input, int argc, char **argv);
void print_vector(int_vector &input);

int main(int argc, char **argv)
{
	int_vector input;
	if (!validate_input(input, argc, argv))
		return 1;

	PmergeMe numbers(input);

	std::cout << "Before:\t" << numbers;

	std::cout << "After:\t" << numbers;

	return 0;
}
