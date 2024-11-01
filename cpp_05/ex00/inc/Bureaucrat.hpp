#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

# define HIGHEST_GRADE	(1)
# define LOWEST_GRADE	(150)

class Bureaucrat
{
	public:
		Bureaucrat(std::string, int);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &rhs);
	
	private:
		const std::string	_name;
		int					_grade;
};

#endif