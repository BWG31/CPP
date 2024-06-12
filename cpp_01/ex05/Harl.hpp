#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define DEBUG_MSG "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-special- ketchup burger.\nI really do!\n"

# define INFO_MSG "I cannot believe adding extra bacon costs more money.\n\
You didn't put enough bacon in my burger!\nIf you did, I wouldn't be asking for more!\n"

# define WARNING_MSG "I think I deserve to have some extra bacon for free.\n\
I've been coming for years whereas you started working here since last month.\n"

# define ERROR_MSG "This is unacceptable! I want to speak to the manager now.\n"

# define DEFAULT_MSG "[ Probably complaining about insignificant problems ]"

class Harl
{
	public:
		void complain( std::string level );
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif