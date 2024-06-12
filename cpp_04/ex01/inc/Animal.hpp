#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

# define RESET	"\033[0m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal(const std::string new_type = "Unknown species");
		Animal(const Animal &other);
		virtual ~Animal();

		Animal &operator=(const Animal &rhs);

		const std::string &getType(void) const;
		virtual void makeSound(void) const;
};

#endif