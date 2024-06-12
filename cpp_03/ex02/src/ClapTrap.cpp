#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap(const std::string new_name): _name(new_name)
{
	_hitPoints = default_hitPoints;
	_energyPoints = default_energyPoints;
	_damage = default_damage;
	std::cout << GREEN << "-- ClapTrap constructor called for: " << _name << " --" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << GREEN << "-- ClapTrap copy constructor called copying: " << other._name << " --" << RESET << std::endl;
	*this = other;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << RED << "-- ClapTrap destructor called for: " << _name << " --" RESET << std::endl;
}

// Assignment operator overload
ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_damage = rhs._damage;
	return (*this);
}

// Member functions
void ClapTrap::attack(const std::string& target)
{
	if (!_energyPoints || !_hitPoints)
	{
		std::cout	<< "⚠️\t" << YELLOW << _name
					<< (!_hitPoints ? " is dead and can't attack." : " is out of energy.")
					<< RESET << std::endl;
		return ;
	}
	std::cout	<< "⚡️\t" << _name << " attacks " << target << ", causing "
				<< _damage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!_hitPoints)
	{
		std::cout << "⚠️\t" << YELLOW << _name << " is already dead." << RESET << std::endl;
		return ;
	}
	_hitPoints < amount ? _hitPoints = 0 : _hitPoints -= amount;
	std::cout	<< "💥\t" << _name << " took " << amount << " damage"
				<< (_hitPoints ? "." : " and died. ☠️") << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!_energyPoints || !_hitPoints)
	{
		std::cout	<< "⚠️\t" << YELLOW << _name
					<< (!_hitPoints ? " is dead and can't repair." : " is out of energy.")
					<< RESET << std::endl;
		return ;
	}
	_hitPoints + amount >= 10 ? _hitPoints = 10 : _hitPoints += amount;
	_energyPoints--;
	std::cout	<< "🛠️\t" << _name << " repaired itself and gained "
				<< amount << " hit points." << std::endl;
}

// Testprint
void ClapTrap::printInfo()
{
	std::cout	<< CYAN << "[ TRAP INFO ]"
				<< "\nName: " << _name
				<< "\nHP: " << _hitPoints
				<< "\t\tEP: " << _energyPoints
				<< "\t\tDmg: " << _damage 
				<< RESET << std::endl;
}
