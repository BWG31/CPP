#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_fixed_value;
		const static int	_point = 8;

	public:
		// Constructors
		Fixed();
		Fixed(const int new_value);
		Fixed(const float new_value);
		Fixed(const Fixed &other);
		// Destructor
		~Fixed();

		// Assignment overload
		Fixed &operator=(const Fixed &rhs);

		// Comparison overloads
		bool operator>(const Fixed &rhs) const;
		bool operator<(const Fixed &rhs) const;
		bool operator>=(const Fixed &rhs) const;
		bool operator<=(const Fixed &rhs) const;
		bool operator==(const Fixed &rhs) const;
		bool operator!=(const Fixed &rhs) const;
		
		// Arithmetic overloads
		Fixed operator+(const Fixed &rhs);
		Fixed operator-(const Fixed &rhs);
		Fixed operator*(const Fixed &rhs);
		Fixed operator/(const Fixed &rhs);
		
		// Increment/Decrement overloads
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);

		// Member functions
		int	getRawBits(void) const;
		void setRawBits (int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		// Static member functions
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

// Output stream overload
std::ostream &operator<<(std::ostream &os, const Fixed &rhs);

#endif