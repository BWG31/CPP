#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		void	attack(void);
	private:
		Weapon		&weapon;
		std::string	name;
};

#endif