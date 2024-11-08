#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>

# include "Bureaucrat.hpp"

# define HIGHEST_FORM_GRADE	(1)
# define LOWEST_FORM_GRADE	(150)

# define DEFAULT_FORM_NAME			"Unknown AForm"
# define DEFAULT_FORM_SIGN_GRADE	(LOWEST_FORM_GRADE)
# define DEFAULT_FORM_EXEC_GRADE	(10)

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(std::string name, int sign_grade, int execute_grade, std::string target);
		AForm(const AForm &other);
		virtual ~AForm();

		AForm &operator=(const AForm &rhs);

		std::string	getName() const;
		bool		getSignedState() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		std::string	getTarget() const;

		void		setSigned(bool state);
		void		setTarget(std::string target);

		void		beSigned(const Bureaucrat &B);
		void		execute(Bureaucrat const & executor) const;
		
		virtual void executeAction() const = 0;

	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_execute_grade;
		std::string			_target;
	
		void		validateGrade(int grade) const;

		class GradeTooHighException;
		class GradeTooLowException;
		class NotSignedException;
};

std::ostream &operator<<(std::ostream &os, const AForm &other);

class AForm::GradeTooHighException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class AForm::GradeTooLowException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class AForm::NotSignedException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

#endif