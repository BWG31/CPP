#include "Contact.hpp"

void Contact::get_new_contact()
{
	std::cout << CYAN << "Creating new contact...\n" << RESET;
	first_name = get_input("First Name: ");
	last_name = get_input("Last Name: ");
	nickname = get_input("Nickname: ");
	phone_number = get_input("Phone Number: ", true);
	secret = get_input("Darkest Secret: ");
}

void Contact::print_info()
{
	std::cout << "First name:\t" << first_name << '\n';
	std::cout << "Last name:\t" << last_name << '\n';
	std::cout << "Nickname:\t" << nickname << '\n';
	std::cout << "Phone number:\t" << phone_number << '\n';
	std::cout << "Secret:\t\t" << secret << std::endl;
}

std::string Contact::get_input(const std::string prompt, bool numeric)
{
	std::string	input;
	bool		valid = false;
	do{
		std::cout << CYAN << prompt << RESET;
		std::getline(std::cin, input);
		if (!input.empty() && (!numeric || valid_number(input)))
			valid = true;
		else
			invalid_input();
	} while (!valid);
	return (input);
}

void Contact::invalid_input()
{
	std::cout << RED << "Invalid input, please try again." << RESET << std::endl;
}

bool Contact::valid_number(const std::string input)
{
	return (input.find_first_not_of("0123456789") == std::string::npos);
}

bool Contact::exists()
{
	return (!first_name.empty());
}
