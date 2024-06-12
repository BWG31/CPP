#include "Point.hpp"

#define LEFT (1)
#define RIGHT (-1)
#define ON_LINE (0)

int orientation(const Point &A, const Point &B, const Point &P)
{
	Fixed result = (B.getX() - A.getX()) * (P.getY() - A.getY()) - \
					(B.getY() - A.getY()) * (P.getX() - A.getX());
	if (result > 0) return LEFT;
	if (result < 0) return RIGHT;
	return ON_LINE;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	int orient_a = orientation(a, b, point);
	if (orient_a == ON_LINE)
		return false;
	int orient_b = orientation(b, c, point);
	if (orient_a != orient_b)
		return false;
	int orient_c = orientation(c, a, point);
	if (orient_a != orient_c)
		return false;
	return true;
}