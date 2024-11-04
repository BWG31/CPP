#include "Bureaucrat.hpp"
#include <iomanip>

//	TESTS
void	test_constructor_1(void);
void	test_constructor_2(void);
void	test_setter(void);
void	test_increment(void);
void	test_decrement(void);

//	HELPERS
void	header(std::string name);
void	print_B(Bureaucrat &B);
void	print_e(std::exception &e);

int	main(void)
{
	test_constructor_1();
	test_constructor_2();

	test_setter();
	test_increment();
	test_decrement();
	return (0);
}

void	test_constructor_1(void)
{
	header("constructor 1");
	try {
		Bureaucrat	Adam("Adam", 1);	//	VALID
		print_B(Adam);
		Bureaucrat	Tom("Tom", 150);	//	VALID
		print_B(Tom);
		Bureaucrat	Frank("Frank", 0);	//	INVALID
		print_B(Frank);
	}
	catch (std::exception &e){
		print_e(e);
	}
}

void	test_constructor_2(void)
{
	header("constructor 2");
	try {
		Bureaucrat	Bob;		//	VALID : Takes DEFAULT values
		print_B(Bob);
		Bob.incrementGrade();
		Bureaucrat	Chris(Bob);	//	VALID : Copy constructor
		print_B(Chris);
	}
	catch (std::exception &e){
		print_e(e);
	}
}

void	test_setter(void)
{
	header("setter");
	try {
		Bureaucrat	Flo("Flo", 1);
		Flo.setGrade(42);
		print_B(Flo);
		Flo.setGrade(151);	//	INVALID
		print_B(Flo);
	}
	catch (std::exception &e){
		print_e(e);
	}
}

void	test_increment(void)
{
	header("increment");
	try {
		Bureaucrat	Louis("Louis", 2);
		print_B(Louis);
		Louis.incrementGrade();	//	VALID
		print_B(Louis);
		Louis.incrementGrade();	//	INVALID
		print_B(Louis);
	}
	catch (std::exception &e)
	{
		print_e(e);
	}
}

void	test_decrement(void)
{
	header("decrement");
	try {
		Bureaucrat	Terry("Terry", 149);
		print_B(Terry);
		Terry.decrementGrade();	//	VALID
		print_B(Terry);
		Terry.decrementGrade();	//	INVALID
		print_B(Terry);
	}
	catch (std::exception &e)
	{
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
