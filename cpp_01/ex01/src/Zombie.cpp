#include "Zombie.hpp"

Zombie::Zombie( void )
{
	name.clear();
}

Zombie::~Zombie( void )
{
	std::cout << RED << name << " was destroyed" << RESET << std::endl;
}

void Zombie::announce( void )
{
	std::cout << GREEN << name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

void Zombie::setName( std::string name )
{
	this->name = name;
}
