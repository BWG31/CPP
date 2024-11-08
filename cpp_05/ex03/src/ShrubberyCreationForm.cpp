#include "ShrubberyCreationForm.hpp"

//  ==========| CONSTRUCTORS |==========
ShrubberyCreationForm::ShrubberyCreationForm() : \
	AForm("Shrubbery Creation", required_sign, required_exec, "default_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : \
	AForm("Shrubbery Creation", required_sign, required_exec, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : \
	AForm(other.getName(), other.getSignGrade(), other.getExecGrade(), other.getTarget())
{
	setSigned(other.getSignedState());
	setTarget(other.getTarget());
}

//  ===========| DESTRUCTOR |===========
ShrubberyCreationForm::~ShrubberyCreationForm() {}

//  =======| OPERATOR OVERLOADS |=======
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this == &rhs)
		return (*this);
	setSigned(rhs.getSignedState());
	setTarget(rhs.getTarget());
	return (*this);
}

//  ============| METHODS |=============

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((getTarget() + "_shrubbery").c_str());
	if (!file)
		throw ShrubFileError();
	file << XMAS_TREE << std::endl;
	file.close();
}

//  ========| VIRTUAL METHODS |=========
