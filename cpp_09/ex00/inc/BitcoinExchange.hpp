#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <string>
# include <fstream>
# include <stdexcept>

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
	
		void checkHeader(std::ifstream &input);
		bool parseData(std::ifstream &input);

		static double convertToDouble(std::string str);
};

const std::string BitcoinExchange::CSV_HEADER_ = "date,exchange_rate";

#endif