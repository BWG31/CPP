#include "Cure.hpp"

//	============= CONSTRUCTORS =============
Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &other) : AMateria("cure")
{
	*this = other;
}

//	============== DESTRUCTOR ==============
Cure::~Cure() {}

//	========== OPERATOR OVERLOADS ==========
Cure &Cure::operator=(const Cure &rhs)
{
	(void)rhs;// NOT SURE
	return (*this);
}

//	=============== METHODS ===============
AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout	<< "* heals " << target.getName()
				<< "'s wounds *" << std::endl;
}
