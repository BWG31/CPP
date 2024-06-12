#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void runTest1(void);
void runTest2(void);

int main(void)
{
	runTest1();
	runTest2();
	return 0;
}

void runTest1(void)
{
	FragTrap *fragbot = new FragTrap("Quentin");
	fragbot->printInfo();
	fragbot->attack("Some chump");
	fragbot->highFivesGuys();
	delete fragbot;
}

void runTest2(void)
{
	ClapTrap *fragbot = new FragTrap(); // Base class pointer to derived class instance
	FragTrap *ptr = dynamic_cast<FragTrap*>(fragbot);
	if (ptr)
	{
		ptr->printInfo();
		ptr->highFivesGuys();
	}
	delete fragbot;
}

/*
	Having to dynamically cast as above is not the best practice as it normally implies a better design should be considered.
	This is done as above to demonstrate the new concepts of the module.
*/
