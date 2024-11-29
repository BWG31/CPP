#include "PmergeMe.hpp"
#include <exception>
#include <sstream>
#include <string>

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

void print_vector(int_vector &input)
{
	for (int_vector::iterator it = input.begin(); it != input.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
}
