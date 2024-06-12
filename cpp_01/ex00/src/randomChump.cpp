#include "Zombie.hpp"
#include <iostream>

void randomChump( std::string name )
{
	Zombie stack_zombie(name);
	stack_zombie.announce();
}
