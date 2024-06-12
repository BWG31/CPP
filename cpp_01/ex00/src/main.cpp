#include <iostream>
#include "Zombie.hpp"


int	main(void)
{
	Zombie *dynamic_zombie = newZombie("John");
	randomChump("Steve");
	dynamic_zombie->announce();
	delete dynamic_zombie;
	return (0);
}
