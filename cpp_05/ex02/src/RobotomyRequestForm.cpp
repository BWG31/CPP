#include "RobotomyRequestForm.hpp"

//  ==========| CONSTRUCTORS |==========
RobotomyRequestForm::RobotomyRequestForm() : \
	AForm("Robotomy Request", required_sign, required_exec, "default_target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : \
	AForm("Robotomy Request", required_sign, required_exec, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : \
	AForm(other.getName(), other.getSignGrade(), other.getExecGrade(), other.getTarget())
{
	setSigned(other.getSignedState());
	setTarget(other.getTarget());
}

//  ===========| DESTRUCTOR |===========
RobotomyRequestForm::~RobotomyRequestForm() {}

//  =======| OPERATOR OVERLOADS |=======
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this == &rhs)
		return (*this);
	setSigned(rhs.getSignedState());
	setTarget(rhs.getTarget());
	return (*this);
}

//  ============| METHODS |=============

void RobotomyRequestForm::executeAction() const
{
	if (getRandom() % 2)
		std::cout << "Vrrr...VRRRRR... " << '\n' \
		<< getTarget() << " has been robotomized successfully" << std::endl;
	else
		throw RobotomyFailed();
}

int	RobotomyRequestForm::getRandom() const
{
	srand(time(NULL) + getpid());
	return (rand());
}

//  ========| VIRTUAL METHODS |=========
