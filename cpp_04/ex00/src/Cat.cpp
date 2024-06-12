#include "Cat.hpp"

// =============== CONSTRUCTORS ==================
Cat::Cat() : Animal("Cat")
{
	std::cout	<< GREEN << "-- Cat constructor called for: "
				<< _type << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal("Cat")
{
	std::cout	<< GREEN << "-- Cat copy constructor called copying: "
				<< other._type << RESET << std::endl;
	*this = other;
}

// ================ DESTRUCTOR ===================
Cat::~Cat()
{
	std::cout	<< RED << "-- Cat destructor called for: "
				<< _type << RESET << std::endl;
}

// ============= OPERATOR OVERLOAD ===============
Cat &Cat::operator=(const Cat &rhs)
{
	_type = rhs._type;
	return (*this);
}

// ================= METHODS ====================
void Cat::makeSound() const
{
	std::cout << "🔈🔈 MEOW MEOW 🔈🔈" << std::endl;
}
