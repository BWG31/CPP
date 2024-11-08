#include "Intern.hpp"

const char *Intern::InvalidFormNameException::what() const throw()
{
	return("Invalid form name");
}
