#include "RPN.hpp"

int main(int argc, char **argv)
{
	try{
		if (argc != 2)
			throw std::invalid_argument("usage: ./rpn <expression>");
		RPN calculator;
		std::cout << calculator.calculate(argv[1]) << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
