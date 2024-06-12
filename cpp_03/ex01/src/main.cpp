#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void runTest1(void);
void runTest2(void);
void runTest3(void);

int main(void)
{
	runTest1(); // ScavTrap test
	runTest2(); // ClapTrap test
	runTest3(); // virtual destructor test
	return 0;
}

void runTest1(void)
{
	std::cout << "\n== TEST 1 ==\n" << std::endl;
	ScavTrap *scav1 = new ScavTrap("Chad");
	scav1->printInfo();
	scav1->attack("George");
	scav1->guardGate();
	scav1->guardGate();
	scav1->takeDamage(101);
	scav1->beRepaired(50);
	scav1->guardGate();
	scav1->printInfo();
	delete scav1;
}

void runTest2(void)
{
	std::cout << "\n== TEST 2 ==\n" << std::endl;
	ClapTrap clap1("Bob");
	clap1.printInfo();
	clap1.attack("Toby");
	clap1.printInfo();
}

void runTest3(void)
{
	std::cout << "\n== TEST 3 ==\n" << std::endl;
	ClapTrap *ptr = new ScavTrap("Alan");
	ptr->printInfo();
	ptr->attack("John");
	ptr->printInfo();
	delete ptr;
}
