#include "Form.hpp"

//  ==========| CONSTRUCTORS |==========
Form::Form() : 
	_name(DEFAULT_FORM_NAME),
	_is_signed(false),
	_sign_grade(DEFAULT_FORM_SIGN_GRADE),
	_execute_grade(DEFAULT_FORM_EXEC_GRADE)
{
	return ;
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
	this->_is_signed = rhs.getState();
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
	return (_is_signed);
}

int Form::getSignGrade() const
{
	return (_sign_grade);
}

int Form::getExecGrade() const
{
	return (_execute_grade);
}

//  ========| VIRTUAL METHODS |=========

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high (Form)");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low (Form)");
}
