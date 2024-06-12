#include "AMateria.hpp"

//	============= CONSTRUCTORS =============
AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

//	============== DESTRUCTOR ==============
AMateria::~AMateria() {}

//	========== OPERATOR OVERLOADS ==========
AMateria &AMateria::operator=(const AMateria &rhs)
{
	(void)rhs;
	return (*this);
}

//	=============== METHODS ===============
std::string const & AMateria::getType() const
{
	return (_type);
}

//	=========== VIRTUAL METHODS ===========
void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cerr << "Incorrect use of AMateria use()" << std::endl;
}