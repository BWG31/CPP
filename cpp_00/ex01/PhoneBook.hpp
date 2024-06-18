#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>

# define MAX_CONTACTS (8)
# define INFO_MSG \
"====================================\n"\
"=                                  =\n"\
"=       My Awesome PhoneBook!      =\n"\
"=                                  =\n"\
"=       Commands:                  =\n"\
"=          - ADD                   =\n"\
"=          - SEARCH                =\n"\
"=          - EXIT                  =\n"\
"=                                  =\n"\
"====================================\n"

# define RESET	"\033[0m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"
# define WHITE	"\033[37m"

class PhoneBook{
	private:
		Contact	contacts[MAX_CONTACTS];
		int		contact_count;

		void		info();
		void		add_new_contact();
		void		search();
		void		print_contact_list();
		void		invalid_command();
		bool		valid_index(int input);
		void		close();
	public:
		PhoneBook();
		void		open();
};

#endif