#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <string>
# include <fstream>
# include <stdexcept>
# include <limits>
# include <cstdlib>

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
		static const std::string CSV_HEADER_;
		static const int KEY_SIZE_ = 10;
		static const int FIRST_DASH_ = 4;
		static const int SECOND_DASH_ = 7;
		static const int YEAR_MIN_ = 2009;
		static const int YEAR_MAX = 2022;
	
		void checkHeader(std::ifstream &input);
		bool parseData(std::ifstream &input);

		static void validateInputKey(std::string &key);
		static double convertToDouble(std::string str);
};

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

const std::string BitcoinExchange::CSV_HEADER_ = "date,exchange_rate";

#endif