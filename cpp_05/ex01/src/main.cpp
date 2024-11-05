#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iomanip>

//	TESTS
void	test_constructors(void);
void	test_sign_form(void);

//	HELPERS
void	header(std::string name);
void	print_B(Bureaucrat &B);
void	print_F(Form &F);
void	print_e(std::exception &e);

int	main(void)
{
	test_constructors();
	test_sign_form();
	return (0);
}

void	test_constructors(void)
{
	header("constructors");
	try {
		Form	form_A;			//	VALID (default values applied)
		print_F(form_A);
		Form	form_B(form_A);	//	VALID (copy constructor)
		print_F(form_B);
		Form 	form_C("Classified Form", 1, 1);	// VALID
		print_F(form_C);
		Form	form_D("Invalid Form", 0, 200);	// INVALID (invalid execute grade)
		print_F(form_D);
	}
	catch (std::exception &e){
		print_e(e);
	}
}

void	test_sign_form(void)
{
	header("sign form");
	try {
		//	Sign form : YES
		Form	not_important("Shopping list", LOWEST_FORM_GRADE, LOWEST_FORM_GRADE);
		print_F(not_important);
		Bureaucrat	somedude("Randy? Or maybe Ralph?", LOWEST_BCT_GRADE);
		print_B(somedude);
		somedude.signForm(not_important);
		print_F(not_important);

		//	Sign form : NO (Grade too low)
		Form	very_important("Secret Document", 10, HIGHEST_FORM_GRADE);
		print_F(very_important);
		somedude.signForm(very_important);
		print_F(very_important);

		//	Promote "somedude" | Sign form : YES
		std::cout << "PROMOTING RALPH (*or was it Randy?*)" << std::endl;
		somedude.setGrade(10);
		somedude.signForm(very_important);
		print_F(very_important);
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
