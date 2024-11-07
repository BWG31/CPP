#include "Bureaucrat.hpp"

//  ==========| CONSTRUCTORS |==========
Bureaucrat::Bureaucrat() : _name(DEFAULT_NAME), _grade(DEFAULT_GRADE) {};

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName())
{
	*this = other;
}

//  ===========| DESTRUCTOR |===========
Bureaucrat::~Bureaucrat()
{
	return ;
}

//  =======| OPERATOR OVERLOADS |=======
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	this->_grade = rhs._grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (os);
}

//  ============| METHODS |=============

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::setGrade(int new_grade)
{
	if (new_grade < HIGHEST_BCT_GRADE)
		throw GradeTooHighException();
	if (new_grade > LOWEST_BCT_GRADE)
		throw GradeTooLowException();
	_grade = new_grade;
}

void Bureaucrat::incrementGrade()
{
	this->setGrade(this->getGrade() - 1);
}

void Bureaucrat::decrementGrade()
{
	this->setGrade(this->getGrade() + 1);
}

void Bureaucrat::signForm(AForm &F)
{
	try {
		F.beSigned(*this);
		std::cout << GREEN << this->getName() << " signed " << F.getName() \
		<< RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << this->getName() << " couldn't sign " << F.getName() << \
		" because: " << e.what() << RESET << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try {
		form.execute(*this);
	}
	catch (std::exception &e) {
		std::cout << RED << getName() << " could not execute form because: " \
		<< e.what() << RESET << std::endl;
		throw ;
	}
	std::cout << GREEN << getName() << " executed " << form.getName() << RESET << std::endl;
}

//  ========| VIRTUAL METHODS |=========

const char  *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char  *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
