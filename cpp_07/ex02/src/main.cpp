#include "Array.hpp"

typedef void (*fptr)();

fptr get_test(int argc, char **argv);
void test_default_constructor();
void test_standard_constructor();
void test_copy_constructor();
void test_assignment_operator();
void test_edge_cases();

int main(int argc, char **argv)
{	
	fptr test = get_test(argc, argv);
	if (test)
		test();
	return (0);
}

fptr get_test(int argc, char **argv)
{
	if (argc == 2)
	{	
		std::string input(argv[1]);
		if (!input.compare("1"))
			return test_default_constructor;
		if (!input.compare("2"))
			return test_standard_constructor;
		if (!input.compare("3"))
			return test_copy_constructor;
		if (!input.compare("4"))
			return test_assignment_operator;
		if (!input.compare("5"))
			return test_edge_cases;
	}
	std::cerr << "Usage: ./runprogram <testnumber>\ntestnumber range: 1-4" << std::endl;
	return (NULL);
}
