#include "Fixed.hpp"

Fixed::Fixed() : _fixed_value(0)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	_fixed_value = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << YELLOW << "getRawBits member function called" << RESET << std::endl;
	return (_fixed_value);
}

void Fixed::setRawBits (int const raw)
{
	std::cout << YELLOW << "getRawBits member function called" << RESET << std::endl;
	_fixed_value = raw;
}
