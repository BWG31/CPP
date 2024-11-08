#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

# define FORM_TYPE_COUNT (3)

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		~Intern();

		Intern &operator=(const Intern &rhs);

		AForm *makeForm(std::string name, std::string target);
	
	private:
		int getFormIndex(std::string name);

		class InvalidFormNameException;
};

class Intern::InvalidFormNameException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

#endif