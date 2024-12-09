#include "PmergeMe.hpp"
#include <iostream>

// main helpers
bool validate_input(int_vector &input, int argc, char **argv);

int main(int argc, char **argv)
{
	int_vector input;
	if (!validate_input(input, argc, argv))
		return 1;

	PmergeMe numbers(input);

	std::cout << "Before:\t" << numbers;
	numbers.mergeInsertionSort();
	std::cout << "After:\t" << numbers;
	std::cout << "Comparisons made: " << numbers.getComparisons() << std::endl;
	std::sort(input.begin(), input.end());
	if (numbers.getNums() != input)
		return 1;
	return 0;
}
