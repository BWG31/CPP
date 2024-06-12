#include "Harl.hpp"

int	incorrect_usage();

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
		return (incorrect_usage());
	harl.complain(argv[1]);
	return (0);
}

int	incorrect_usage()
{
	std::cout << RED << "Usage: ./harl_filter DEBUG|INFO|WARNING|ERROR"
	<< RESET << std::endl;
	return (1);
}
