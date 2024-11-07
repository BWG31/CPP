#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

		virtual void executeAction() const;
	
	private:

		static const int 	required_sign = 145;
		static const int	required_exec = 137;

		class ShrubFileError : public std::exception
		{
			public:
				virtual const char *what() const throw(){
					return ("Unable to open target file");
				}
		};
};

#endif