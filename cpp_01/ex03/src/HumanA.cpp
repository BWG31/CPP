#include <string>
#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon), name(name) {}

void HumanA::attack(void)
{
	std::cout << name << " attacks with their ";
	if (!weapon.getType().empty())
		std::cout << weapon.getType();
	else
		std::cout << "bare hands";
	std::cout << std::endl;
}
