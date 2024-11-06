#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iomanip>

//	TESTS
void	test_constructors(void);
void	test_execute_form(void);

//	HELPERS
void	header(std::string name);
void	print_B(Bureaucrat &B);
void	print_F(AForm &F);
void	print_e(std::exception &e);

int	main(void)
{
	test_constructors();
	test_execute_form();
	return (0);
}

void	test_constructors(void)
{
	header("constructors");
	try {
		ShrubberyCreationForm	ShrubA("abc");
		ShrubberyCreationForm	ShrubC("123");
		print_F(ShrubA);
		print_F(ShrubC);
		ShrubC = ShrubA;
		print_F(ShrubC);
	}
	catch (std::exception &e){
		print_e(e);
	}
}

void	test_execute_form(void)
{
	header("sign form");
	try {
		//	DO STUFF
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
