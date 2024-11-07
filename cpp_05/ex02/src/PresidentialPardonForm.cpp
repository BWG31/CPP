#include "PresidentialPardonForm.hpp"

//  ==========| CONSTRUCTORS |==========
PresidentialPardonForm::PresidentialPardonForm() : \
	AForm("Presidential Pardon", required_sign, required_exec, "default_target") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : \
	AForm("Presidential Pardon", required_sign, required_exec, target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : \
	AForm(other.getName(), other.getSignGrade(), other.getExecGrade(), other.getTarget())
{
	setSigned(other.getSignedState());
	setTarget(other.getTarget());
}

//  ===========| DESTRUCTOR |===========
PresidentialPardonForm::~PresidentialPardonForm() {}

//  =======| OPERATOR OVERLOADS |=======
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this == &rhs)
		return (*this);
	setSigned(rhs.getSignedState());
	setTarget(rhs.getTarget());
	return (*this);
}

//  ============| METHODS |=============

void PresidentialPardonForm::executeAction() const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

//  ========| VIRTUAL METHODS |=========
