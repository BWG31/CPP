#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iomanip>

//	TESTS
void	test_constructors(void);
void	test_shrubbery(void);
void	test_robotomy(void);
void	test_presidential_pardon(void);
void	check_randomizer_accuracy(void);

//	HELPERS
void	header(std::string name);
void	print_B(Bureaucrat &B);
void	print_F(AForm &F);
void	print_e(std::exception &e);

int	main(void)
{
	test_constructors();
	test_shrubbery();
	test_presidential_pardon();
	test_robotomy();
	check_randomizer_accuracy();
	return (0);
}

void	test_constructors(void)
{
	header("constructors");
	try {
		ShrubberyCreationForm	ShrubA("abc");
		ShrubberyCreationForm	ShrubC("123");
		ShrubberyCreationForm	ShrubCopy(ShrubC);
		ShrubberyCreationForm	ShrubDefault;
		print_F(ShrubA);
		print_F(ShrubC);
		print_F(ShrubCopy);
		print_F(ShrubDefault);
	}
	catch (std::exception &e){
		print_e(e);
	}
}

void	test_shrubbery(void)
{
	header("sign form");
	try {
		ShrubberyCreationForm	shrub_form("garden");
		Bureaucrat				CEO("Boss", 1);
		CEO.signForm(shrub_form);
		CEO.executeForm(shrub_form);	// Should execute form OK
	
		Bureaucrat	peon("Peon", 150);
		peon.executeForm(shrub_form);	// Rank too low, should throw
	}
	catch (std::exception &e){
		print_e(e);
	}
}

void	test_robotomy(void)
{
	header("robotomy");
	try {
		RobotomyRequestForm	robotomy("Randle McMurphy");
		Bureaucrat			nurse("Ratched", 30);
	
		nurse.signForm(robotomy);
		nurse.executeForm(robotomy);	// Should execute form OK
	
		Bureaucrat			chief("Chief", 100);
		chief.executeForm(robotomy);	//	Rank too low, should throw
	}
	catch (std::exception &e){
		print_e(e);
	}
}

void	test_presidential_pardon(void)
{
	header("presidential pardon");
	try {
		PresidentialPardonForm	form("Vincent");
		Bureaucrat				LeCapitaine("Christophe", 1);
		LeCapitaine.signForm(form);
		LeCapitaine.executeForm(form);	// Should execute form OK
	
		Bureaucrat	Alexis("Alexis", 15);
		Alexis.executeForm(form);	//	Rank too low, should throw
	}
	catch (std::exception &e){
		print_e(e);
	}
}

void	check_randomizer_accuracy(void)
{
	header("Randomizer accuracy check");
	RobotomyRequestForm robot;
	int fail_count = 0;
	int iterations = 100000;
	srand(time(NULL) + getpid());
	for (int i = 0; i < iterations; i++)
	{
		if (rand() % 2)
			fail_count++;
	}
	std::cout << (double)fail_count / iterations * 100 << " % fail rate" << std::endl;
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
