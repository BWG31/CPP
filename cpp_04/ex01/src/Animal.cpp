#include "Animal.hpp"

// =============== CONSTRUCTORS ==================
Animal::Animal(const std::string new_type) : _type(new_type)
{
	std::cout	<< GREEN << "-- Animal constructor called for: "
				<< _type << RESET << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout	<< GREEN << "-- Animal copy constructor called copying: "
				<< other._type << RESET << std::endl;
	*this = other;
}

// ================ DESTRUCTOR ===================
Animal::~Animal()
{
	std::cout	<< RED << "-- Animal destructor called for: "
				<< _type << RESET << std::endl;
}

// ============= OPERATOR OVERLOAD ===============
Animal &Animal::operator=(const Animal &rhs)
{
	_type = rhs._type;
	return (*this);
}

// ================= METHODS ====================
const std::string &Animal::getType() const
{
	return (_type);
}

void Animal::makeSound() const
{
	std::cout << "🔈🔈 STRANGE NOISES 🔈🔈" << std::endl;
}
