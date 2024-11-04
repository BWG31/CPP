#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iomanip>

//	TESTS
void	test_constructor_1(void);

//	HELPERS
void	header(std::string name);
void	print_B(Bureaucrat &B);
void	print_F(Form &F);
void	print_e(std::exception &e);

int	main(void)
{
	test_constructor_1();

	return (0);
}

void	test_constructor_1(void)
{
	header("constructor 1");
	try {
		Form	form_A;
		print_F(form_A);
		Form	form_B(form_A);
		print_F(form_B);
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

void	print_F(Form &F)
{
	std::cout << F << std::endl;
}
