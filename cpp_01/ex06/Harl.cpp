#include "Harl.hpp"

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;
	for (i = 0; i < 4; i++)
		if (level == levels[i])
			break;
	switch (i){
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break;
		default:
			std::cout << DEFAULT_MSG << std::endl;
	}
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n" << DEBUG_MSG << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]\n" << INFO_MSG << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]\n" << WARNING_MSG << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\n" << ERROR_MSG << std::endl;
}
