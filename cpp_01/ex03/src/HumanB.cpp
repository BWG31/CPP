#include <string>
#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : weapon(nullptr), name(name) {}

void HumanB::attack(void)
{
	std::cout << name << " attacks with their ";
	if (weapon)
		std::cout << weapon->getType();
	else
		std::cout << "bare hands";
	std::cout << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
