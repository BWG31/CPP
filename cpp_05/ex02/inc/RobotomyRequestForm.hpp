#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <fstream>
# include <cstdlib>
# include <unistd.h>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

		virtual void executeAction() const;
	
	private:

		static const int 	required_sign = 72;
		static const int	required_exec = 45;

		int	getRandom() const;

		class RobotomyFailed;
};

class RobotomyRequestForm::RobotomyFailed : public std::exception
{
	public:
		virtual const char *what() const throw();
};

#endif