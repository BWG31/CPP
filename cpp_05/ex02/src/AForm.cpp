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

AForm::AForm(std::string name, int sign_grade, int execute_grade) :
	_name(name),
	_signed(false),
	_sign_grade(sign_grade),
	_execute_grade(execute_grade)
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
	this->_signed = rhs.getState();
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const AForm &other)
{
	os << "Form: " << other.getName() << "\t| signed: " << other.getState();
	os << "\t| sign grade: " << other.getSignGrade();
	os << "\t| exec grade: " << other.getExecGrade();
	return (os);
}

//  ============| METHODS |=============

std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getState() const
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

void AForm::validateGrade(int grade) const
{
	if (grade < HIGHEST_FORM_GRADE)
		throw GradeTooHighException();
	if (grade > LOWEST_FORM_GRADE)
		throw GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat &B)
{
	if (B.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	else
		this->_signed = true;
}

//  ========| VIRTUAL METHODS |=========

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
