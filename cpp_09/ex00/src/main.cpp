#include "BitcoinExchange.hpp"
#include <iostream>
#include <exception>

const std::string BitcoinExchange::CSV_FILE_ = "data.csv";
const std::string BitcoinExchange::CSV_HEADER_ = "date,exchange_rate";

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./btc <input file>" << std::endl;
		return 1;
	}
	try{
		BitcoinExchange exchange;
		std::cout << exchange;
	}catch (const std::exception &e){
		std::cerr << "Error: " << e.what() << std::endl;
		return 2;
	}
	(void)argv;
	return 0;
}
