#include "AAnimal.hpp"

// =============== CONSTRUCTORS ==================
AAnimal::AAnimal(const std::string new_type) : _type(new_type)
{
	std::cout	<< GREEN << "-- AAnimal constructor called for: "
				<< _type << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout	<< GREEN << "-- AAnimal copy constructor called copying: "
				<< other._type << RESET << std::endl;
	*this = other;
}

// ================ DESTRUCTOR ===================
AAnimal::~AAnimal()
{
	std::cout	<< RED << "-- AAnimal destructor called for: "
				<< _type << RESET << std::endl;
}

// ============= OPERATOR OVERLOAD ===============
AAnimal &AAnimal::operator=(const AAnimal &rhs)
{
	_type = rhs._type;
	return (*this);
}

// ================= METHODS ====================
const std::string &AAnimal::getType() const
{
	return (_type);
}
