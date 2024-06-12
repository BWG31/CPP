#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		// Constructors | Destructor
		Cure();
		Cure(const Cure &other);
		~Cure();

		// Operator Overloads
		Cure &operator=(const Cure &rhs);

		// Methods
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
