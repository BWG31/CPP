#include "Point.hpp"

// ----- Constructors -----
Point::Point(): _x(0), _y(0) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::Point(const Point &other):
	_x(other.getX()), 
	_y(other.getY()) {}

// ----- Destructor -----

Point::~Point() {}

// ----- Assignment overload -----
Point &Point::operator=(const Point &rhs)
{
	(void)rhs;
	std::cout << "Assignment overload: All members are constants: "\
				"Unable to make any assignments." << std::endl;
	return (*this);
}

// ----- Member functions -----


Fixed Point::getX() const
{
	return (_x);
}

Fixed Point::getY() const
{
	return (_y);
}

// ----- Output stream overload -----
std::ostream &operator<<(std::ostream &os, const Point &rhs)
{
	os << "(" << rhs.getX() << ", " << rhs.getY() << ")";
	return (os);
}
