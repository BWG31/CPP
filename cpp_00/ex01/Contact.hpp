#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

# define RESET	"\033[0m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"
# define CYAN	"\033[36m"
# define WHITE	"\033[37m"

class Contact{
	private:
		std::string	phone_number;
		std::string	secret;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;

		std::string	get_input(const std::string prompt, bool numeric = false);
		bool		only_whitespace(const std::string input);
		void		invalid_input();
		bool		valid_number(const std::string input);
		std::string	truncated_name(std::string name);
	
	public:
		Contact		&operator=(const Contact &rhs);
	
		void		get_new_contact();
		void		preview();
		void 		print_info();
		bool		exists();
};

#endif