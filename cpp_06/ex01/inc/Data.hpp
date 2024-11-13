#ifndef DATA_HPP
# define DATA_HPP

# include <string>
# include <iomanip>

class Data
{
	public:
		Data();
		Data(const Data &other);
		~Data();

		Data &operator=(const Data &rhs);

		int			getNumber() const;
		char 		getChar() const;
		std::string	getMessage() const;

	private:
		int			number;
		char		character;
		std::string	secret_message;
};

std::ostream &operator<<(std::ostream &os, const Data &rhs);

#endif