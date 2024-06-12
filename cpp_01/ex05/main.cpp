#include "Harl.hpp"
#include <unistd.h>

int main(void)
{
	Harl harl;
	harl.complain("DEBUG");
	sleep(2);
	harl.complain("INFO");
	sleep(2);
	harl.complain("WARNING");
	sleep(2);
	harl.complain("ERROR");
	return (0);
}
