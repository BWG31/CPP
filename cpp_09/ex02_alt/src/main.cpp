#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	int_vector	input_vector, vector_copy;
	int_deq		input_deque, deque_copy;

	if (!validate_input(input_vector, argc, argv))
		return 1;
	print_container(input_vector);

	// Copy input_vector to input_deque
	input_deque.resize(input_vector.size());
	std::copy(input_vector.begin(), input_vector.end(), input_deque.begin());

	// Make copies for later sorting validation with checkSorted()
	vector_copy = input_vector;
	deque_copy = input_deque;

	// Display before state
	std::cout << "Before:\t";
	print_container(input_vector);
	
	PmergeMe(input_vector);
	PmergeMe(input_deque);

	std::cout << "After:\t";
	print_container(input_vector);

	return (checkSorted(input_vector, vector_copy, "vector") | \
			checkSorted(input_deque, deque_copy, "deque"));
}
