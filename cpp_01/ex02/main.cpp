#include <iostream>
#include <string>

int main(void)
{
	std::string	my_string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &my_string;
	std::string &stringREF = my_string;

	std::cout << "my_string memory address:\t\t" << &my_string << '\n';
	std::cout << "memory address held by stringPTR:\t" << stringPTR << '\n';
	std::cout << "memory address held by stringREF:\t" << &stringREF << std::endl;

	std::cout << "\nvalue of my_string:\t\t" << my_string << '\n';
	std::cout << "value pointed to by stringPTR:\t" << *stringPTR << '\n';
	std::cout << "value pointed to by stringREF:\t" << stringREF << std::endl;

	return (0);
}