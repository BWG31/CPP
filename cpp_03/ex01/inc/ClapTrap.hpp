#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <iostream>
#include <string>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define CYAN	"\033[36m"

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_damage;

	public:
		ClapTrap(const std::string new_name = "Unknown");
		ClapTrap(const ClapTrap &other);
		virtual ~ClapTrap();

		ClapTrap &operator=(const ClapTrap &rhs);

		// Member functions
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		// Testing utilities
		void printInfo(void);

		// Default variable values
		static const unsigned int default_hitPoints = 10;
		static const unsigned int default_energyPoints = 10;
		static const unsigned int default_damage = 0;
};

#endif