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
	int_vector input_copy(input);
	std::sort(input_copy.begin(), input_copy.end());
	if (input != input_copy)
		std::cout << "\033[31m";
	else
		std::cout << "\033[32m";
	print_vector(input);
	std::cout << "\033[0m";

	return 0;
}
