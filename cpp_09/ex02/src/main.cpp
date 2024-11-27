#include "PmergeMe.hpp"
#include <exception>
#include <iostream>

// main helpers
bool validate_input(std::vector<int> &input, int argc, char **argv);
void display_before(std::vector<int> &input);

int main(int argc, char **argv)
{
	std::vector<int> input;
	if (!validate_input(input, argc, argv))
		return 1;
	display_before(input);

	PmergeMe v(input);

	std::cout << v;
	return 0;
}
