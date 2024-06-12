#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <string>
# include <iostream>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &other);
		~Cat();

		Cat &operator=(const Cat &rhs);

		void makeSound(void) const;
};

#endif