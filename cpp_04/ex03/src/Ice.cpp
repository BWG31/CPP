#include "Ice.hpp"

//	============= CONSTRUCTORS =============
Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &other) : AMateria("ice")
{
	*this = other;
}

//	============== DESTRUCTOR ==============
Ice::~Ice() {}

//	========== OPERATOR OVERLOADS ==========
Ice &Ice::operator=(const Ice &rhs)
{
	(void)rhs;// NOT SURE
	return (*this);
}

//	=============== METHODS ===============
AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout	<< "* shoots an ice bolt at " 
				<< target.getName() << "*" << std::endl;
}
