#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

# define RESET	"\033[0m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"

class Zombie
{
	public:
		Zombie( void );
		~Zombie( void );

		void	announce( void );
		void	setName( std::string name );
	private:
		std::string	name;
};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );
Zombie	*zombieHorde( int N, std::string name);

#endif