#include "WrongAnimal.hpp"

// =============== CONSTRUCTORS ==================
WrongAnimal::WrongAnimal(const std::string new_type) : _type(new_type)
{
	std::cout	<< GREEN << "-- WrongAnimal constructor called for: "
				<< _type << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout	<< GREEN << "-- WrongAnimal copy constructor called copying: "
				<< other._type << RESET << std::endl;
	*this = other;
}

// ================ DESTRUCTOR ===================
WrongAnimal::~WrongAnimal()
{
	std::cout	<< RED << "-- WrongAnimal destructor called for: "
				<< _type << RESET << std::endl;
}

// ============= OPERATOR OVERLOAD ===============
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	_type = rhs._type;
	return (*this);
}

// ================= METHODS ====================
const std::string &WrongAnimal::getType() const
{
	return (_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "🔈🔈 SQUANTCH! 🔈🔈" << std::endl;
}
