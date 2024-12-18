#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <string>
# include <fstream>
# include <stdexcept>
# include <limits>
# include <cstdlib>
# include <iomanip>

# define CSV_FILE	"data.csv"
# define CSV_HEADER	"date,exchange_rate"

typedef std::map<std::string, double> t_data;

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &rhs);
	
		const t_data &getData() const;

	private:
		t_data	data_;
	
		// Constants for parsing
		static const int KEY_SIZE_ = 10;
		static const int FIRST_DASH_ = 4;
		static const int SECOND_DASH_ = 7;
		static const int YEAR_MIN_ = 2009;
		static const int YEAR_MAX_ = 2022;

		void checkHeader(std::ifstream &input);
		void parseLine(std::string &line, std::string seperator);
		int parseData();

		static std::string validateInputKey(std::string key);
		static void validateDate(int year, int month, int day);
		static double convertToDouble(std::string str);
};

std::ostream &operator<<(std::ostream &os, const BitcoinExchange &rhs);

enum e_months
{
	JAN = 1,
	FEB,
	MAR,
	APR,
	MAY,
	JUN,
	JUL,
	AUG,
	SEP,
	OCT,
	NOV,
	DEC,
};

#endif