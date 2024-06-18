#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contacts(), contact_count(0) {}

void PhoneBook::open()
{
	std::string	input;

	info();
	while (true)
	{
		std::cout << YELLOW << "Enter Command: " << RESET;
		if (!std::getline(std::cin, input))
		{
			std::cerr << RED << "EOF detected. Aborting program." << RESET << std::endl;
			exit(EXIT_FAILURE);
		}
		if (input == "ADD")
			add_new_contact();
		else if (input == "SEARCH")
			search();
		else if (input == "EXIT")
			break;
		else
			invalid_command();
	}
	close();
}

void PhoneBook::info()
{
	std::cout << YELLOW << INFO_MSG << RESET << std::endl;
}

void PhoneBook::add_new_contact()
{
	static int	index = 0;

	if (contact_count == MAX_CONTACTS)
	{
		for (int i = 0; i < MAX_CONTACTS - 1; i++)
			contacts[i] = contacts[i + 1];
	}
	else
		contact_count++;
	contacts[index].get_new_contact();
	std::cout	<< GREEN << "Successfully added new contact at index: "
				<< index << RESET << std::endl;
	if (index < MAX_CONTACTS - 1)
		index++;
}

void PhoneBook::search()
{
	int			input;

	if (!contacts->exists())
	{
		std::cout << RED << "Phonebook is empty!" << RESET << std::endl;
		return ;
	}
	print_contact_list();
	while (true)
	{
		std::cout << YELLOW << "Enter index number: " << RESET;
		std::cin >> input;
		if (std::cin.eof())
		{
			std::cerr << RED << "EOF detected. Aborting program." << RESET << std::endl;
			exit(EXIT_FAILURE);
		}
		if (std::cin.fail() || !valid_index(input))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << RED << "Invalid index" << RESET << std::endl;
		}
		else
			break;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	contacts[input].print_info();
}

void PhoneBook::print_contact_list()
{
	std::cout << std::setfill(' ');
	std::cout << std::setw(10) << CYAN << "INDEX";
	std::cout << std::setw(11) << "FIRST_NAME";
	std::cout << std::setw(11) << "LAST_NAME";
	std::cout << std::setw(11) << "NICKNAME\n" << RESET;
	for (int i = 0; (i < MAX_CONTACTS) && (contacts[i].exists()); i++)
	{
		std::cout << std::setw(10) << i;
		std::cout << "|";
		contacts[i].preview();
	}
}

void PhoneBook::invalid_command()
{
	std::cout << RED << "Invalid command. Options: ADD, SEARCH, EXIT" << RESET << std::endl;
}

bool PhoneBook::valid_index(const int input)
{
	if (input < MAX_CONTACTS && contacts[input].exists())
		return (true);
	return (false);
}

void PhoneBook::close()
{
	std::cout << YELLOW << "Exiting Phonebook... Goodbye!" << RESET << std::endl;
}
