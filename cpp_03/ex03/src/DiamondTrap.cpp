#include "DiamondTrap.hpp"

// Constructors
DiamondTrap::DiamondTrap(const std::string new_name): ClapTrap(new_name + "_clap_name")
{
	this->name = new_name;
	this->_hitPoints = FragTrap::default_hitPoints;
	this->_energyPoints = ScavTrap::default_energyPoints;
	this->_damage = FragTrap::default_damage;
	std::cout << GREEN << "-- DiamondTrap constructor called for: " << name << " --" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	std::cout << GREEN << "-- DiamondTrap copy constructor called copying: " << other.name << " --" << RESET << std::endl;
	*this = other;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "-- DiamondTrap destructor called for: " << name << " --" RESET << std::endl;
}

// Assignment operator overload
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_damage = rhs._damage;
	return (*this);
}

// Member functions
void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
void DiamondTrap::whoAmI()
{
	std::cout	<< "My DiamondTrap name is: " << name << "\n"
				<< "My ClapTrap name is: " << this->ClapTrap::_name << std::endl;
}
