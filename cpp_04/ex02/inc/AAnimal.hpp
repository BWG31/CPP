#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include <iostream>

# define RESET	"\033[0m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"

class AAnimal
{
	protected:
		std::string	_type;
	public:
		AAnimal(const std::string new_type = "Unknown species");
		AAnimal(const AAnimal &other);
		virtual ~AAnimal();

		AAnimal &operator=(const AAnimal &rhs);

		const std::string &getType(void) const;
		virtual void makeSound(void) const = 0;
};

#endif