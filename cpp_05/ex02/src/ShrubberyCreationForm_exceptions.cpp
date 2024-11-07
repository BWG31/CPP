#include "ShrubberyCreationForm.hpp"

const char *ShrubberyCreationForm::ShrubFileError::what() const throw()
{
	return ("Unable to open target file");
}
