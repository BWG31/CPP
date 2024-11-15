#include "Array.hpp"
#include <iostream>
#include <limits>

void test_default_constructor()
{
	std::cout << "\n[[[ TEST DEFAULT CONSTRUCTOR ]]]" << std::endl;
	try {
		Array<char> letters;
		std::cout << letters;

		Array<int>	numbers;
		std::cout << numbers;

		int i = numbers[0];
		std::cout << i << std::endl;
	}
	catch (std::exception &e){
		std::cerr << "test_default_constructor caught: " << e.what() << std::endl;
	}
}

void test_standard_constructor()
{
	std::cout << "\n[[[ TEST STANDARD CONSTRUCTOR ]]]" << std::endl;
	try {
		Array<int>	numbers(10);
		std::cout << numbers;

		numbers[5] = 42;
		std::cout << numbers;
	}
	catch (std::exception &e){
		std::cerr << "test_standard_constructor caught: " << e.what() << std::endl;
	}
}

void test_copy_constructor()
{
	std::cout << "\n[[[ TEST COPY CONSTRUCTOR ]]]" << std::endl;
	try {
		Array<char> letters(3);
		std::cout << letters;

		letters[0] = 'A';
		std::cout << letters;
	
		Array<char>	copy(letters);
		std::cout << copy;
	
		copy[2] = 'C';
		std::cout << letters;
		std::cout << copy;
	}
	catch (std::exception &e){
		std::cerr << "test_copy_constructor caught: " << e.what() << std::endl;
	}
}

void test_assignment_operator()
{
	std::cout << "\n[[[ TEST ASSIGNMENT OPERATOR ]]]" << std::endl;
	try {
		Array<double> numbers(5);
		numbers[4] = 42.42;
		std::cout << numbers;
	
		Array<double> copy = numbers;
		copy[4] = 21.21;
		std::cout << numbers;
		std::cout << copy;
	}
	catch (std::exception &e){
		std::cerr << "test_assignment_operator caught: " << e.what() << std::endl;
	}
}

void test_edge_cases()
{
	std::cout << "\n[[[ TEST EDGE CASES ]]]" << std::endl;
	Array<int> numbers(3);
	try {
		std::cout << "Accessing index [-1]" << std::endl;
		numbers[-1] = 42;
	}
	catch (std::exception &e){
		std::cerr << "test_assignment_operator caught: " << e.what() << std::endl;
	}
	try {
		std::cout << "Accessing index [size_t::min() -1]" << std::endl;
		numbers[std::numeric_limits<size_t>::min() - 1] = 42;
	}
	catch (std::exception &e){
		std::cerr << "test_assignment_operator caught: " << e.what() << std::endl;
	}
	try {
		std::cout << "Accessing index [size_t::max() + 1]" << std::endl;
		numbers[std::numeric_limits<size_t>::max() + 1] = 42;
		std::cout << "No catch because (size_t::max() + 1) wraps around to 0" << std::endl;
	}
	catch (std::exception &e){
		std::cerr << "test_assignment_operator caught: " << e.what() << std::endl;
	}
	try {
		std::cout << "Accessing index [3287423984732]" << std::endl;
		numbers[3287423984732] = 42;
	}
	catch (std::exception &e){
		std::cerr << "test_assignment_operator caught: " << e.what() << std::endl;
	}
	std::cout << numbers;
}
