#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		// Constructors
		Point();
		Point(const float x, const float y);
		Point(const Point &other);
		// Destructor
		~Point();
		// Assignment overload
		Point &operator=(const Point &rhs);
		// Member functions
		Fixed getX() const;
		Fixed getY() const;
};

// Output stream overload
std::ostream &operator<<(std::ostream &os, const Point &rhs);

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif