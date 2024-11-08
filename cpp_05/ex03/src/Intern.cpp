#include "Intern.hpp"

//  ==========| CONSTRUCTORS |==========
Intern::Intern() {}

Intern::Intern(const Intern &other)
{
    *this = other;
}

//  ===========| DESTRUCTOR |===========
Intern::~Intern() {}

//  =======| OPERATOR OVERLOADS |=======
Intern &Intern::operator=(const Intern &rhs)
{
	(void)rhs;
    return (*this);
}

//  ============| METHODS |=============
AForm *Intern::makeForm(std::string name, std::string target)
{
	int index = getFormIndex(name);

	switch (index){
		case 0: return (new ShrubberyCreationForm(target));
		case 1:	return (new RobotomyRequestForm(target));
		case 2:	return (new PresidentialPardonForm(target));
		default:
			throw InvalidFormNameException();
	}
}

int Intern::getFormIndex(std::string name)
{
	const std::string form_names[FORM_TYPE_COUNT] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < FORM_TYPE_COUNT; i++)
	{
		if (name.compare(form_names[i]) == 0)
			return (i);
	}
	return (-1);
}

//  ========| VIRTUAL METHODS |=========
