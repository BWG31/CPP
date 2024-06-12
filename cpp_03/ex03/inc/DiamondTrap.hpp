#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap ,public FragTrap
{
	private:
		std::string name;
	public:
		DiamondTrap(const std::string new_name = "Unknown");
		DiamondTrap(const DiamondTrap &other);
		~DiamondTrap();

		DiamondTrap &operator=(const DiamondTrap &rhs);

		void attack(const std::string& target);
		void whoAmI(void);
};

#endif