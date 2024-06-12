#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"

class WrongAnimal
{
	protected:
		std::string	_type;
	public:
		WrongAnimal(const std::string new_type = "Unknown species");
		WrongAnimal(const WrongAnimal &other);
		virtual ~WrongAnimal();

		WrongAnimal &operator=(const WrongAnimal &rhs);

		const std::string &getType(void) const;
		void makeSound(void) const;
};

#endif