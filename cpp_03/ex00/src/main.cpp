#include "ClapTrap.hpp"

void runTest1(void);

int main(void)
{
	runTest1();
	return 0;
}

void runTest1(void)
{
	ClapTrap *unit1 = new ClapTrap("Steve");

	unit1->printInfo();

	unit1->attack("Jerry");
	unit1->takeDamage(5);
	unit1->printInfo();
	unit1->beRepaired(1);
	for (int i = 0; i < 9; i++) // deplete energy points
		unit1->attack("Gary");
	unit1->printInfo();
	unit1->takeDamage(10); // hp: 0
	unit1->printInfo();
	unit1->attack("Jerry");
	unit1->beRepaired(10);
	unit1->takeDamage(5);
	unit1->printInfo();

	// Copy through assignment
	ClapTrap unit2;
	unit2 = *unit1;
	unit2.printInfo();
	unit2.attack("Fred");

	delete unit1;
}
