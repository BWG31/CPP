#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

# define HIGHEST_GRADE	(1)
# define LOWEST_GRADE	(150)

# define DEFAULT_NAME	"Unknown"
# define DEFAULT_GRADE	(LOWEST_GRADE)

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

std::ostream &operator<<(std::ostream &os ,const Bureaucrat &other);

#endif