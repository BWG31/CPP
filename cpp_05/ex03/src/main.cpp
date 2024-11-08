#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include <iomanip>

//	TESTS
void	test_intern(void);

//	HELPERS
void	header(std::string name);
void	print_B(Bureaucrat &B);
void	print_F(AForm &F);
void	print_e(std::exception &e);

int	main(void)
{
	test_intern();
	return (0);
}

void	test_intern(void)
{
	try {
		Bureaucrat	Tony("Boss", 1);
		Intern		Chris;
		AForm		*newform;

		header("Shrubbery test");
		newform = Chris.makeForm("shrubbery creation", "park");
		Tony.signForm(*newform);
		Tony.executeForm(*newform);
		delete newform;

		header("Robotomy test");
		newform = Chris.makeForm("robotomy request", "Johnny");
		Tony.signForm(*newform);
		Tony.executeForm(*newform);
		delete newform;

		header("Presidential test");
		newform = Chris.makeForm("presidential pardon", "Vinnie");
		Tony.signForm(*newform);
		Tony.executeForm(*newform);
		delete newform;

		header("Invalid form test");
		newform = Chris.makeForm("non existent form", "earth");
		Tony.signForm(*newform);
		Tony.executeForm(*newform);
		delete newform;

	}
	catch (std::exception &e){
		print_e(e);
	}
}

void	header(std::string name)
{
	std::cout << YELLOW << "\n=====| TEST " << name << " |=====" << RESET << std::endl;
}

void	print_B(Bureaucrat &B)
{
	std::cout << B << std::endl;
}

void	print_e(std::exception &e)
{
	std::cout << RED << "Caught an exception: " << e.what() << RESET << std::endl;
}

void	print_F(AForm &F)
{
	std::cout << F << std::endl;
}
