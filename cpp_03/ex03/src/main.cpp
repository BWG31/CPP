#include "DiamondTrap.hpp"

void runTest1(void);
void runTest2(void);
void runTest3(void);
void print_seperator(void);

int main(void)
{
	runTest1();
	runTest2();
	runTest3();
	return 0;
}

void runTest1(void)
{
	print_seperator();
	std::cout << "|| START OF TEST 1 ||" << std::endl;
	print_seperator();

	DiamondTrap *D = new DiamondTrap("Adam");
	print_seperator();
	D->printInfo();
	print_seperator();
	D->attack("Billy");
	print_seperator();
	D->whoAmI();
	print_seperator();
	delete D;

	print_seperator();
	std::cout << "|| END OF TEST 1 ||" << std::endl;
	print_seperator();
}

void runTest2(void)
{
	print_seperator();
	std::cout << "|| START OF TEST 2 ||" << std::endl;
	print_seperator();

	DiamondTrap *attacker = new DiamondTrap("Luke");
	FragTrap *defender = new FragTrap("Anakin");
	
	print_seperator();

	attacker->printInfo();
	defender->printInfo();

	print_seperator();

	attacker->attack(defender->getName());
	defender->takeDamage(attacker->getDamage());
	
	print_seperator();

	attacker->printInfo();
	defender->printInfo();

	print_seperator();

	delete attacker;
	delete defender;

	print_seperator();
	std::cout << "|| END OF TEST 2 ||" << std::endl;
	print_seperator();
}

void runTest3()
{
	print_seperator();
	std::cout << "|| START OF TEST 3 ||" << std::endl;
	print_seperator();

	ClapTrap *attacker = new ClapTrap("Palpatine");
	DiamondTrap *defender = new DiamondTrap("Kevin the Storm Trooper");
	
	print_seperator();
	
	attacker->printInfo();
	defender->printInfo();

	print_seperator();

	attacker->attack(defender->getName());
	defender->takeDamage(attacker->getDamage());

	print_seperator();
	
	attacker->printInfo();
	defender->printInfo();
	
	print_seperator();

	defender->attack(attacker->getName());
	attacker->takeDamage(defender->getDamage());

	print_seperator();
	
	attacker->printInfo();
	defender->printInfo();
	
	print_seperator();
	
	delete attacker;
	delete defender;
	
	print_seperator();
	std::cout << "|| END OF TEST 3 ||" << std::endl;
	print_seperator();
}

void print_seperator()
{
	std::cout << "\n" << std::string(40, '=') << "\n" << std::endl;
}
