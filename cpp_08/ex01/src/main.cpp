#include "Span.hpp"
#include <iostream>
#include <ctime>

// PROTOTYPES
void pdf_test();
void custom_test();
void empty_span_test();
void single_element_test();
void randomize(int &n);

int main()
{
	pdf_test();
	custom_test();
	empty_span_test();
	single_element_test();
	return 0;
}

// TESTERS
void pdf_test()
{
	std::cout << "== PDF TEST ==\n";
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}


void custom_test()
{
	std::cout << "\n== CUSTOM TEST ==\n";

	// Initialize empty span (capacity of 100'000)
	Span sp(100000);
	std::cout << sp;

	// Create vector of 10 random integers
	std::vector<int> nums(10);
	srand(time(NULL));
	std::for_each(nums.begin(), nums.end(), randomize);

	// Add nums to span
	sp.addRange(nums.begin(), nums.end());

	std::cout << sp;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

// Sets n to a random number between -999 and 999
void randomize(int &n)
{
	n = rand() % 2000 - 1000;
}

void empty_span_test()
{
	// EMPTY SPAN EXCEPTIONS
	std::cout << "\n== EMPTY SPAN TESTS ==\n";
	Span sp(0);
	try{
		std::cout << sp.shortestSpan();
		std::cout << "THIS SHOULD NOT PRINT (1)" << std::endl;
	} catch (std::exception &e){
		std::cerr << "Caught exception (1): " << e.what() << std::endl;
	}
	try{
		std::cout << sp.longestSpan();
		std::cout << "THIS SHOULD NOT PRINT (2)" << std::endl;
	} catch (std::exception &e){
		std::cerr << "Caught exception (2): " << e.what() << std::endl;
	}
	try{
		sp.addNumber(42);
		std::cout << "THIS SHOULD NOT PRINT (3)" << std::endl;
	} catch (std::exception &e){
		std::cerr << "Caught exception (3): " << e.what() << std::endl;
	}
}

void single_element_test()
{
	// SIGNLE ELEMENT EXCEPTIONS
	std::cout << "\n== SINGLE ELEMENT TESTS ==\n";
	Span sp(1);
	sp.addNumber(42);
	try{
		std::cout << sp.shortestSpan();
		std::cout << "THIS SHOULD NOT PRINT (1)" << std::endl;
	} catch (std::exception &e){
		std::cerr << "Caught exception (1): " << e.what() << std::endl;
	}
	try{
		std::cout << sp.longestSpan();
		std::cout << "THIS SHOULD NOT PRINT (2)" << std::endl;
	} catch (std::exception &e){
		std::cerr << "Caught exception (2): " << e.what() << std::endl;
	}
	try{
		sp.addNumber(42);
		std::cout << "THIS SHOULD NOT PRINT (3)" << std::endl;
	} catch (std::exception &e){
		std::cerr << "Caught exception (3): " << e.what() << std::endl;
	}
}
