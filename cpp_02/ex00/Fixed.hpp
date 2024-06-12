#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"

class Fixed
{
	private:
		int					_fixed_value;
		const static int	_point = 8;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &rhs);
		~Fixed();
		int	getRawBits(void) const;
		void setRawBits (int const raw);
};

#endif