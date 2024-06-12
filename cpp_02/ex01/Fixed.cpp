#include "Fixed.hpp"

Fixed::Fixed() : _fixed_value(0)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int new_value)
{
	std::cout << GREEN << "Int constructor called" << RESET << std::endl;
	this->setRawBits(new_value << _point);
}

Fixed::Fixed(const float new_value)
{
	std::cout << GREEN << "Float constructor called" << RESET << std::endl;
	_fixed_value = roundl(new_value * (1 << _point));
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
	return (_fixed_value);
}

void Fixed::setRawBits (int const raw)
{
	_fixed_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float) _fixed_value / (1 << _point));
}

int Fixed::toInt(void) const
{
	return (_fixed_value >> _point);
}

std::ostream &operator<<(std::ostream &os, const Fixed &rhs)
{
	os << rhs.toFloat();
	return (os);
}
