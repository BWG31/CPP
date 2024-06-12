#include "Dog.hpp"

// =============== CONSTRUCTORS ==================
Dog::Dog() : Animal("Dog")
{
	std::cout	<< GREEN << "-- Dog constructor called for: "
				<< _type << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal("Dog")
{
	std::cout	<< GREEN << "-- Dog copy constructor called copying: "
				<< other._type << RESET << std::endl;
	*this = other;
}

// ================ DESTRUCTOR ===================
Dog::~Dog()
{
	std::cout	<< RED << "-- Dog destructor called for: "
				<< _type << RESET << std::endl;
}

// ============= OPERATOR OVERLOAD ===============
Dog &Dog::operator=(const Dog &rhs)
{
	_type = rhs._type;
	return (*this);
}

// ================= METHODS ====================
void Dog::makeSound() const
{
	std::cout << "🔈🔈 WOOF WOOF 🔈🔈" << std::endl;
}
