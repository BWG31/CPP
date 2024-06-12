#include "Fixed.hpp"

// ----- Constructors -----
Fixed::Fixed() : _fixed_value(0) {}

Fixed::Fixed(const int new_value)
{
	this->setRawBits(new_value << _point);
}

Fixed::Fixed(const float new_value)
{
	_fixed_value = roundl(new_value * (1 << _point));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

// ----- Destructor -----
Fixed::~Fixed() {}

// ----- Assignment overload -----
Fixed &Fixed::operator=(const Fixed &rhs)
{
	_fixed_value = rhs.getRawBits();
	return (*this);
}

// ----- Comparison overloads -----
bool Fixed::operator>(const Fixed &rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (!this->operator<(rhs));
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (!this->operator>(rhs));
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

// ----- Arithmetic overloads -----
Fixed Fixed::operator+(const Fixed &rhs)
{
	Fixed result(*this);
	result._fixed_value += rhs.getRawBits();
	return (result);
}

Fixed Fixed::operator-(const Fixed &rhs)
{
	Fixed result(*this);
	result._fixed_value -= rhs.getRawBits();
	return (result);
}

Fixed Fixed::operator*(const Fixed &rhs)
{
	Fixed result(this->toFloat() * rhs.toFloat());
	return (result);
}

Fixed Fixed::operator/(const Fixed &rhs)
{
	Fixed result(this->toFloat() / rhs.toFloat());
	return (result);
}


// ----- Increment/Decrement overloads -----
Fixed Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	Fixed temp(*this);
	return (temp);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->setRawBits(this->getRawBits() + 1);
	return (temp);
}

Fixed Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	Fixed temp(*this);
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->setRawBits(this->getRawBits() - 1);
	return (temp);
}


// ----- Member functions -----
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

// ----- Static member functions -----
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);
}


// ----- Output stream overload -----
std::ostream &operator<<(std::ostream &os, const Fixed &rhs)
{
	os << rhs.toFloat();
	return (os);
}
