#include "BitcoinExchange.hpp"
#include <iostream>
#include <exception>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./btc <input file>" << std::endl;
		return 1;
	}
	try{
		BitcoinExchange exchange;
		exchange.calculate(argv[1]);
	}catch (const std::exception &e){
		std::cerr << "Error: " << e.what() << std::endl;
		return 2;
	}
	(void)argv;
	return 0;
}
