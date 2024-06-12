#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; argv[i]; i++)
	{
		for (char *c = argv[i]; *c; c++)
			*c = std::toupper(*c);
		std::cout << argv[i];
	}
	std::cout << std::endl;
	return (0);
}
