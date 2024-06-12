#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
		bool _gate_keeper_mode;
	public:
		ScavTrap(const std::string new_name = "Unknown");
		ScavTrap(const ScavTrap &other);
		~ScavTrap();

		ScavTrap &operator=(const ScavTrap &rhs);

		void attack(const std::string& target);
		void guardGate();

		static const unsigned int default_hitPoints = 100;
		static const unsigned int default_energyPoints = 50;
		static const unsigned int default_damage = 20;
		static const unsigned int default_gate_keeper_mode = false;
};

#endif