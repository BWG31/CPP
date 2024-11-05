#include "Form.hpp"

//  ==========| CONSTRUCTORS |==========
Form::Form() : 
	_name(DEFAULT_FORM_NAME),
	_signed(false),
	_sign_grade(DEFAULT_FORM_SIGN_GRADE),
	_execute_grade(DEFAULT_FORM_EXEC_GRADE)
{
	return ;
}

Form::Form(std::string name, int sign_grade, int execute_grade) :
	_name(name),
	_signed(false),
	_sign_grade(sign_grade),
	_execute_grade(execute_grade)
{
	validateGrade(sign_grade);
	validateGrade(execute_grade);
}

Form::Form(const Form &other) :
	_name(other.getName()),
	_sign_grade(other.getSignGrade()),
	_execute_grade(other.getExecGrade())
{
	*this = other;
}

//  ===========| DESTRUCTOR |===========
Form::~Form()
{
	return ;
}

//  =======| OPERATOR OVERLOADS |=======
Form &Form::operator=(const Form &rhs)
{
	this->_signed = rhs.getState();
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Form &other)
{
	os << "Form: " << other.getName() << "\t| signed: " << other.getState();
	os << "\t| sign grade: " << other.getSignGrade();
	os << "\t| exec grade: " << other.getExecGrade();
	return (os);
}

//  ============| METHODS |=============

std::string Form::getName() const
{
	return (_name);
}

bool Form::getState() const
{
	return (_signed);
}

int Form::getSignGrade() const
{
	return (_sign_grade);
}

int Form::getExecGrade() const
{
	return (_execute_grade);
}

void Form::validateGrade(int grade) const
{
	if (grade < HIGHEST_FORM_GRADE)
		throw GradeTooHighException();
	if (grade > LOWEST_FORM_GRADE)
		throw GradeTooLowException();
}

void Form::beSigned(const Bureaucrat &B)
{
	if (B.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	else
		this->_signed = true;
}

//  ========| VIRTUAL METHODS |=========

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
