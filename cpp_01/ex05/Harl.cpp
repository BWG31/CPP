#include "Harl.hpp"

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*function[])(void) = {	&Harl::debug, 
										&Harl::info,
										&Harl::warning,
										&Harl::error};
	for (int i = 0; i < 4; i++)
		if (level == levels[i])
			return (this->*function[i])();
	std::cout << DEFAULT_MSG << std::endl;
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
