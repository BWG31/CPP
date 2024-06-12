#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(const std::string new_name = "Unknown");
		FragTrap(const FragTrap &other);
		~FragTrap();

		FragTrap &operator=(const FragTrap &rhs);

		void attack(const std::string& target);
		void highFivesGuys(void);

		static const unsigned int default_hitPoints = 100;
		static const unsigned int default_energyPoints = 100;
		static const unsigned int default_damage = 30;
};

#endif