#include "PmergeMe.hpp"

extern int size;

void print_timing(double time, std::string type)
{
	std::cout << "Time to process a range of " << size;
	std::cout << " elements with std::" << type << " : \t";
	std::cout << time << " ms" << std::endl;
}
