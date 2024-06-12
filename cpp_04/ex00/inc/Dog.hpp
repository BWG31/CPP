#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <string>
# include <iostream>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &other);
		~Dog();

		Dog &operator=(const Dog &rhs);

		void makeSound(void) const;
};

#endif