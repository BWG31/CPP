#include "PmergeMe.hpp"
#include <exception>
#include <iostream>
#include <cmath>

// main helpers
bool validate_input(int_vector &input, int argc, char **argv);

int main(int argc, char **argv)
{
	int_vector input;
	if (!validate_input(input, argc, argv))
		return 1;

	int_vector input_copy(input);
	int_deq input_deque(input.size());

	std::cout << "Before:\t";
	print_container(input);
	

	std::copy(input.begin(), input.end(), input_deque.begin());
	print_container(input_deque);
	
	PmergeMe(input_deque);
	PmergeMe(input);
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
	print_container(input);
	print_container(input_deque);
	std::cout << "\033[0m";
	return status;
}
