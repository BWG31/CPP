#include "Contact.hpp"

Contact &Contact::operator=(const Contact &rhs)
{
	this->phone_number = rhs.phone_number;
	this->secret = rhs.secret;
	this->first_name = rhs.first_name;
	this->last_name = rhs.last_name;
	this->nickname = rhs.nickname;
	return (*this);
}

void Contact::get_new_contact()
{
	std::cout << CYAN << "Creating new contact...\n" << RESET;
	first_name = get_input("First Name: ");
	last_name = get_input("Last Name: ");
	nickname = get_input("Nickname: ");
	phone_number = get_input("Phone Number: ", true);
	secret = get_input("Darkest Secret: ");
}

void Contact::preview()
{
		std::cout << std::setw(10) << truncated_name(first_name);
		std::cout << "|";
		std::cout << std::setw(10) << truncated_name(last_name);
		std::cout << "|";
		std::cout << std::setw(10) << truncated_name(nickname) << std::endl;
}

std::string Contact::truncated_name(std::string name)
{
	if (name.length() > 10)
		return (name.substr(0, 9) + ".");
	return (name);
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
		if (!std::getline(std::cin, input)){
			std::cerr << RED << "EOF detected. Aborting program." << RESET << std::endl;
			exit(EXIT_FAILURE);
		}
		if (!input.empty() && !only_whitespace(input) && (!numeric || valid_number(input)))
			valid = true;
		else
			invalid_input();
	} while (!valid);
	return (input);
}

bool Contact::only_whitespace(const std::string input)
{
	return (input.find_first_not_of(" \f\n\r\t\v") == std::string::npos);
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
