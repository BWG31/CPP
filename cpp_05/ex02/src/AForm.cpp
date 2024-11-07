#include "AForm.hpp"

//  ==========| CONSTRUCTORS |==========
AForm::AForm() : 
	_name(DEFAULT_FORM_NAME),
	_signed(false),
	_sign_grade(DEFAULT_FORM_SIGN_GRADE),
	_execute_grade(DEFAULT_FORM_EXEC_GRADE)
{
	return ;
}

AForm::AForm(std::string name, int sign_grade, int execute_grade, std::string target) :
	_name(name),
	_signed(false),
	_sign_grade(sign_grade),
	_execute_grade(execute_grade),
	_target(target)
{
	validateGrade(sign_grade);
	validateGrade(execute_grade);
}

AForm::AForm(const AForm &other) :
	_name(other.getName()),
	_sign_grade(other.getSignGrade()),
	_execute_grade(other.getExecGrade())
{
	*this = other;
}

//  ===========| DESTRUCTOR |===========
AForm::~AForm()
{
	return ;
}

//  =======| OPERATOR OVERLOADS |=======
AForm &AForm::operator=(const AForm &rhs)
{
	if (this == &rhs)
		return (*this);
	_signed = rhs.getSignedState();
	_target = rhs.getTarget();
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const AForm &other)
{
	os << "Form: " << other.getName() << "\t| signed: " << other.getSignedState();
	os << "\t| sign grade: " << other.getSignGrade();
	os << "\t| exec grade: " << other.getExecGrade();
	os << "\t| target: " << other.getTarget();
	return (os);
}

//  ============| METHODS |=============

std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getSignedState() const
{
	return (_signed);
}

int AForm::getSignGrade() const
{
	return (_sign_grade);
}

int AForm::getExecGrade() const
{
	return (_execute_grade);
}

std::string AForm::getTarget() const
{
	return (_target);
}

void AForm::validateGrade(int grade) const
{
	if (grade < HIGHEST_FORM_GRADE)
		throw GradeTooHighException();
	if (grade > LOWEST_FORM_GRADE)
		throw GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat &B)
{
	if (B.getGrade() > getSignGrade())
		throw GradeTooLowException();
	setSigned(true);
}

void AForm::setSigned(bool state)
{
	_signed = state;
}

void AForm::setTarget(std::string target)
{
	_target = target;
}

void AForm::execute(Bureaucrat const & executor)

{
	if (getSignedState() == false)
		throw NotSignedException();
	if (getExecGrade() < executor.getGrade())
		throw GradeTooLowException();
	executeAction();
}

//  ========| VIRTUAL METHODS |=========
