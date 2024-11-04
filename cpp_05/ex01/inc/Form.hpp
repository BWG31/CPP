#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>

# define DEFAULT_FORM_NAME			"Unknown Form"
# define DEFAULT_FORM_SIGN_GRADE	(150)
# define DEFAULT_FORM_EXEC_GRADE	(10)

class Form
{
	public:
		Form();
		Form(const Form &other);
		~Form();

		Form &operator=(const Form &rhs);

		std::string	getName() const;
		bool		getState() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_sign_grade;
		const int			_execute_grade;
	
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