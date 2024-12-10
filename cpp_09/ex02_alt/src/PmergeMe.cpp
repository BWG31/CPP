#include "PmergeMe.hpp"

/*
	Returns the number of elements to insert based on the given step (starting at 1)
	The mathematical sequence is: 0, 2, 2, 6, 10, 22, 42, etc...
*/
size_t nextInSequence(const size_t &step)
{
	return (round((pow(2, step) + pow(-1, step)) / 3));
}
