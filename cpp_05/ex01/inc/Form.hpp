#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>

# include "Bureaucrat.hpp"

# define HIGHEST_FORM_GRADE	(1)
# define LOWEST_FORM_GRADE	(150)

# define DEFAULT_FORM_NAME			"Unknown Form"
# define DEFAULT_FORM_SIGN_GRADE	(LOWEST_FORM_GRADE)
# define DEFAULT_FORM_EXEC_GRADE	(10)

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string name, int sign_grade, int execute_grade);
		Form(const Form &other);
		~Form();

		Form &operator=(const Form &rhs);

		std::string	getName() const;
		bool		getState() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		void		beSigned(const Bureaucrat &B);

	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_execute_grade;
	
		void		validateGrade(int grade) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Form &other);

#endif