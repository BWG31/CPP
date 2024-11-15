#include <iostream>
#include <string>
#include <fstream>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"

int	invalid_input();
int file_error(std::string str);
int main(int argc, char **argv)
{
	if (argc != 4 || !strlen(argv[2]) || !strlen(argv[3]))
		return (invalid_input());
	
	std::string		filename = argv[1];
	std::string		new_file = filename + ".replace";
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	std::ifstream	in_file;
	std::ofstream	out_file;

	in_file.open(filename);
	if (in_file.is_open())
	{
		out_file.open(new_file);
		if (out_file.is_open())
		{
			for (std::string line; getline(in_file, line); )
			{
				for (std::size_t found = line.find(s1);
					found != std::string::npos;
					found = line.find(s1, found + s2.length()))
				{
					line.erase(found, s1.length());
					line.insert(found, s2);
				}
				out_file << line << std::endl;
			}
			std::cout << GREEN << "New modified file: " << new_file << RESET << std::endl;
		}
		else
			return (file_error(new_file));
	}
	else
		return (file_error(filename));
	in_file.close();
	out_file.close();
	return (0);
}

int	invalid_input()
{
	std::cout 
		<< RED << "Invalid input.\n" 
		<< "Usage: ./sed_pro <file> <string to replace> <replace with>"
		<< RESET << std::endl;
	return (1);
}

int file_error(std::string str)
{
	std::cout << RED << "Error opening file: " << str << RESET << std::endl;
	return (2);
}
