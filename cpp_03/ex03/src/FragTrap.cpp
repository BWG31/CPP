#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap(const std::string new_name): ClapTrap(new_name)
{
	_hitPoints = default_hitPoints;
	_energyPoints = default_energyPoints;
	_damage = default_damage;
	std::cout << GREEN << "-- FragTrap constructor called for: " << _name << " --" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
	std::cout << GREEN << "-- FragTrap copy constructor called copying: " << other._name << " --" << RESET << std::endl;
	*this = other;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << RED << "-- FragTrap destructor called for: " << _name << " --" RESET << std::endl;
}

// Assignment operator overload
FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_damage = rhs._damage;
	return (*this);
}

// Member functions
void FragTrap::attack(const std::string& target)
{
	if (!_energyPoints || !_hitPoints)
	{
		std::cout	<< "⚠️\t" << YELLOW << _name
					<< (!_hitPoints ? " is dead and can't attack." : " is out of energy.")
					<< RESET << std::endl;
		return ;
	}
	std::cout	<< "⚡️\t" << _name << " stomps on " << target << "'s foot causing "
				<< _damage << " points of damage! Ouch..." << std::endl;
	_energyPoints--;
}

void FragTrap::highFivesGuys()
{
	if (!_energyPoints)
		std::cout << "⚠️\t" << YELLOW << _name << " is out of energy and can't high five." << RESET << std::endl;
	else
	{
		std::cout << "✋\t" << _name << ": \"HIGH FIVE!\"\t*SLAP*\t\"Yeah man, I'm gonna live forever!\"" << std::endl;
		_energyPoints--;
	}
}
