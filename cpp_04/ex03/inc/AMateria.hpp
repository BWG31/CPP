#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

# define RESET	"\033[0m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"

class ICharacter;

class AMateria
{
	protected:
		const std::string	_type;
	public:
		// Constructors | Destructor
		AMateria(std::string const & type);
		AMateria(const AMateria &other);
		virtual ~AMateria();

		// Operator Overloads
		AMateria &operator=(const AMateria &rhs);

		// Methods
		std::string const & getType() const;

		// Virtual Methods
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif