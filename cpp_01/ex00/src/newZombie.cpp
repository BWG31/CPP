#include "Zombie.hpp"
#include <new>

Zombie *newZombie( std::string name )
{
	return (new Zombie(name));
}
