#include "Zombie.hpp"

int main(void)
{
	int			horde_size;
	std::string	name;
	Zombie		*horde;

	std::cout << YELLOW << "Zombie Horde Size: " << RESET;
	std::cin >> horde_size;
	if (std::cin.fail() || horde_size < 1) 
	{
		std::cout << RED << "Input error." << RESET << std::endl;
		return 1;
	}
	std::cin.clear();
	std::cout << YELLOW << "Enter Zombie Name: " << RESET;
	std::cin >> name;
	if (name.empty() || !name.size())
	{
		std::cout << YELLOW << "Fine I'll pick then." << RESET << std::endl;
		name = "Jerry";
	}
	horde = zombieHorde(horde_size, name);
	for (int i = 0; i < horde_size; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}
