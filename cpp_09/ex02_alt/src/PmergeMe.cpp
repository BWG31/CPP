#include "PmergeMe.hpp"
#include <exception>
#include <sstream>
#include <string>

// ==== INPUT VALIDATION ====

static void parse_input(int_vector &input, int argc, char **argv)
{
	if (argc < 2 || argc > 10001)
		throw std::invalid_argument("Invalid argument count: must be 1 to 10'000");
	for (int i = 1, num = -1; i < argc; ++i)
	{
		std::istringstream iss(argv[i]);
		if (!(iss >> num) || !iss.eof() || num < 0)
			throw std::invalid_argument("Invalid argument detected");
		input.push_back(num);
	}
	std::cout << "Parsing complete" << std::endl;
}

bool validate_input(int_vector &input, int argc, char **argv)
{
	try{
		parse_input(input, argc, argv);

	} catch (std::exception &e){
		std::cerr << "\033[31mError: " << e.what() << "\033[0m" << std::endl;
		return false;
	}
	return true;
}

// ==== ALGORITHM HELPERS ====

/*
	Returns the number of elements to insert based on the given step (starting at 1)
	The mathematical sequence is: 0, 2, 2, 6, 10, 22, 42, etc...
*/
size_t nextInSequence(const size_t &step)
{
	return (round((pow(2, step) + pow(-1, step)) / 3));
}
