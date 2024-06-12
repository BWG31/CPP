#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		// Constructors | Destructor
		Ice();
		Ice(const Ice &other);
		~Ice();

		// Operator Overloads
		Ice &operator=(const Ice &rhs);

		// Methods
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif