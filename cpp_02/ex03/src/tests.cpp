#include <iostream>
#include "Point.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"

void print_test_info(const Point &P, const Point &A, \
					const Point &B, const Point &C)
{
	static int i = 1;
	std::cout << YELLOW << "===== TEST " << i++ << "=====\n" << RESET;
	std::cout << "A" << A << "  B" << B << "  C" << C << std::endl;
	std::cout << "P" << P << "\n";
}

void print_result(bool result)
{
	if (result == true)
		std::cout << GREEN << "Point is inside triangle\n";
	else
		std::cout <<  RED<< "Point not inside triangle\n";
	std::cout << RESET << std::endl;
}

void runTest1()
{
	Point P(6, 2), A(4, 1), B(8, 1), C(6, 4);
	print_test_info(P, A, B, C);
	print_result(bsp(A, B, C, P));
}

void runTest2()
{
	Point P(2, 10), A(1, 1), B(2, 5), C(5, 2);
	print_test_info(P, A, B, C);
	print_result(bsp(A, B, C, P));
}

void runTest3()
{
	Point P(3.2f, 4.7f), A(0.1f, 5.4), B(10.42f, 6.11f), C(4.24f, 0);
	print_test_info(P, A, B, C);
	print_result(bsp(A, B, C, P));
}

void runTest4()
{
	Point P(2, 2), A(0, 0), B(5, 5), C(5, 0);
	print_test_info(P, A, B, C);
	print_result(bsp(A, B, C, P));
}

void runTest5()
{
	Point P(-2, -1), A(0, 0), B(-5, -5), C(-5, 0);
	print_test_info(P, A, B, C);
	print_result(bsp(A, B, C, P));
}

void run_bsp_tests()
{
	runTest1();
	runTest2();
	runTest3();
	runTest4();
	runTest5();
}
