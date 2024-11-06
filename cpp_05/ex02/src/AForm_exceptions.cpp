#include "AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("Form not signed");
}
