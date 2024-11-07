#include "RobotomyRequestForm.hpp"

const char *RobotomyRequestForm::RobotomyFailed::what() const throw()
{
	return ("Robotomy Failed");
}
