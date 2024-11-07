#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

# include "AForm.hpp"

# define HIGHEST_BCT_GRADE	(1)
# define LOWEST_BCT_GRADE	(150)

# define DEFAULT_NAME	"Unknown"
# define DEFAULT_GRADE	(LOWEST_BCT_GRADE)

# define RESET	"\033[0m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string, int);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &rhs);

		std::string getName() const;
		int			getGrade() const;
	
		void		setGrade(int new_grade);
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(AForm &F);
		void		executeForm(AForm const & form);

	private:
		const std::string	_name;
		int					_grade;

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &other);

#endif