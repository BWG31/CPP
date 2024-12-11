#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <string>

int retval = 0;
int size = 0;

void print_timing(double time, std::string type);

template <typename Container>
double timed_execution(int argc, char **argv)
{
	std::clock_t start, end;

	start = std::clock();

	PmergeMe<Container> object(argc, argv);
	size = object.getNums().size();
	std::cout << "Before:\t" << object;
	object.mergeInsertionSort();
	if (!(object.isSorted()))
	{
		std::cout << RED;
		retval++;
	}
	else
		std::cout << GREEN;
	std::cout << "After:\t" << object << RST;

	end = std::clock();
	return (1000.0 * (end - start) / CLOCKS_PER_SEC);
}

int main(int argc, char **argv)
{
	double time_vector, time_deque;

	try{
		time_vector = timed_execution<std::vector<int> >(argc, argv);
		time_deque = timed_execution<std::deque<int> >(argc, argv);
	}
	catch (std::exception &e){
		std::cerr << RED"Error\n" << e.what() << RST << std::endl;
		return -1;
	}
	print_timing(time_vector, "vector");
	print_timing(time_deque, "deque");
	return retval;
}
