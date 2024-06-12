#include "WrongCat.hpp"

// =============== CONSTRUCTORS ==================
WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout	<< GREEN << "-- WrongCat constructor called for: "
				<< _type << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	std::cout	<< GREEN << "-- WrongCat copy constructor called copying: "
				<< other._type << RESET << std::endl;
	*this = other;
}

// ================ DESTRUCTOR ===================
WrongCat::~WrongCat()
{
	std::cout	<< RED << "-- WrongCat destructor called for: "
				<< _type << RESET << std::endl;
}

// ============= OPERATOR OVERLOAD ===============
WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	_type = rhs._type;
	return (*this);
}

// ================= METHODS ====================
void WrongCat::makeSound() const
{
	std::cout << "🔈🔈 MOOOOOOOOOO 🔈🔈" << std::endl;
}
