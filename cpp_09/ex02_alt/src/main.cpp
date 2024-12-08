#include "PmergeMe.hpp"
#include <exception>
#include <iostream>
#include <cmath>

// main helpers
bool validate_input(int_vector &input, int argc, char **argv);
void print_vector(int_vector &input);

int COMPS = 0;

int main(int argc, char **argv)
{
	int_vector input;
	if (!validate_input(input, argc, argv))
		return 1;
	std::cout << "Before:\t";
	print_vector(input);

	int_vector input_copy(input);
	
	PmergeMe(input, 1);

	// VALIDATE SORT

	int status = 0;

	std::cout << "After:\t";
	std::sort(input_copy.begin(), input_copy.end());
	if (input != input_copy)
	{
		std::cout << "\033[31m";
		status = 1;
	}
	else
		std::cout << "\033[32m";
	print_vector(input);
	std::cout << "\033[0m";
	std::cout << "COMPS: " << COMPS << std::endl;
	return status;
}
