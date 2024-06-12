#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap(const std::string new_name): ClapTrap(new_name)
{
	_hitPoints = default_hitPoints;
	_energyPoints = default_energyPoints;
	_damage = default_damage;
	_gate_keeper_mode = default_gate_keeper_mode;
	std::cout << GREEN << "-- ScavTrap constructor called for: " << _name << " --" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << GREEN << "-- ScavTrap copy constructor called copying: " << other._name << " --" << RESET << std::endl;
	*this = other;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << RED << "-- ScavTrap destructor called for: " << _name << " --" RESET << std::endl;
}

// Assignment operator overload
ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_damage = rhs._damage;
	_gate_keeper_mode = rhs._gate_keeper_mode;
	return (*this);
}

// Member functions
void ScavTrap::attack(const std::string& target)
{
	if (!_energyPoints || !_hitPoints)
	{
		std::cout	<< "⚠️\t" << YELLOW << _name
					<< (!_hitPoints ? " is dead and can't attack." : " is out of energy.")
					<< RESET << std::endl;
		return ;
	}
	std::cout	<< "⚡️\t" << _name << " punches " << target << " in the face and causes "
				<< _damage << " points of damage! That must hurt..." << std::endl;
	_energyPoints--;
}

void ScavTrap::guardGate()
{
	if (_gate_keeper_mode || !_hitPoints)
	{
		std::cout	<< "⚠️\t" << YELLOW << _name
					<< (!_hitPoints ? " is dead and cannot guard the gate." : " already in Gate keeper mode.")
					<< RESET << std::endl;
		return ;
	}
	_gate_keeper_mode = true;
	std::cout << "🛡️\t" << _name << " now in Gate keeper mode." << std::endl;
}
