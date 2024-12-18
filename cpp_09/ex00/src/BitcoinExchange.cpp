#include "BitcoinExchange.hpp"

//  ==========| CONSTRUCTORS |==========
BitcoinExchange::BitcoinExchange()
{
	if (parseData() != 0)
		throw std::runtime_error("Data parsing errors detected");
	std::cout << "Data file parsing complete" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

//  ===========| DESTRUCTOR |===========
BitcoinExchange::~BitcoinExchange()
{

}

//  =======| OPERATOR OVERLOADS |=======
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (&rhs == this)
		return *this;
	data_ = rhs.getData();
	return *this;
}

//  ============| GETTERS |=============

const t_data &BitcoinExchange::getData() const { return data_; }

//  ============| METHODS |=============

int BitcoinExchange::parseData()
{
	std::ifstream input(CSV_FILE, std::ifstream::in);
	if (!input.good())
		throw std::runtime_error("Unable to open " CSV_FILE);

	int	error = 0;
	checkHeader(input);
	for (size_t line = 2; input.good(); line++)
	{
		try{
			std::string line;
			getline(input, line);
			if (line.size())
				parseLine(line, ",");
		}
		catch (const std::exception &e){
			error = 1;
			std::cerr << "Error (Line " << line << "): " << e.what() << std::endl;
		}
	}
	if (!input.eof())
		throw std::runtime_error("Unexpected end to data parsing");
	input.close();
	return error;
}

void BitcoinExchange::checkHeader(std::ifstream &input)
{
	std::string first_line;
	getline(input, first_line);
	if (first_line.compare(CSV_HEADER))
		throw std::invalid_argument("Invalid csv header:" + first_line + "\texpected: " + CSV_HEADER);
}

void BitcoinExchange::parseLine(std::string &line, std::string seperator)
{
	std::pair<t_data::iterator, bool>   state;
	std::pair<std::string, double>	toInsert;

	size_t pos = line.find(seperator);
	if (pos == std::string::npos)
		throw std::invalid_argument("No seperator found: " + seperator);

	toInsert.first = validateInputKey(line.substr(0, pos));
	toInsert.second = convertToDouble(line.substr(pos + seperator.size()));
	state = data_.insert(toInsert);
	if (state.second == false)
		throw std::runtime_error("Insert failed for: " + line);
}

//  ============| STATIC METHODS |=============

std::string BitcoinExchange::validateInputKey(std::string key)
{
	if (key.find_first_not_of("0123456789-") != std::string::npos || \
		key.size() != KEY_SIZE_ || key[FIRST_DASH_] != '-' || key[SECOND_DASH_] != '-')
		throw std::invalid_argument("Invalid date format: [" + key + "]");
	
	int year, month, day;
	year = std::atoi(key.substr(0, FIRST_DASH_).c_str());
	month = std::atoi(key.substr(FIRST_DASH_ + 1, SECOND_DASH_).c_str());
	day = std::atoi(key.substr(SECOND_DASH_ + 1).c_str());

	validateDate(year, month, day);
	return key;
}

void BitcoinExchange::validateDate(int year, int month, int day)
{
	if (year < YEAR_MIN_ || year > YEAR_MAX_)
		throw std::invalid_argument("Invalid year");
	if (month < JAN || month > DEC)
		throw std::invalid_argument("Invalid month");
	if (day < 1 || day > 31)
		throw std::invalid_argument("Invalid day");
	if ((month == APR || month == JUN || month == SEP || month == NOV)\
		&& day == 31)
		throw std::invalid_argument("Invalid day (31) in month");
	if (month == FEB && ((year % 4 && day > 28) || (!(year % 4) && day > 29)))
		throw std::invalid_argument("Invalid day in FEB");
}

double  BitcoinExchange::convertToDouble(std::string str)
{
	const char	*c_str = str.c_str();
	char 		*end = NULL;
	double		value;

	errno = 0;
	value = std::strtod(c_str, &end);
	if (c_str == end)
		throw std::invalid_argument("Unable to convert to double: [" + str + ']');
	if (errno == ERANGE)
		throw std::invalid_argument("Out of double range: [" + str + ']');
	if (end && *end != '\0')
		throw std::invalid_argument("Invalid trailing character(s): [" + str + ']');
	if (value < 0)
		throw std::invalid_argument("Not a positive number: [" + str + ']');
	if (value > std::numeric_limits<int>::max())
		throw std::invalid_argument("Too large a number: [" + str + ']');
	return (value);
}


//  ========| VIRTUAL METHODS |=========

//  ========| NON MEMBER FUNCTIONS |=========
std::ostream &operator<<(std::ostream &os, const BitcoinExchange &rhs)
{
	os << std::setprecision(7);
	for (t_data::const_iterator it = rhs.getData().begin(); it != rhs.getData().end(); ++it)
	{
		os << "Key: " << it->first << "\tValue: " << it->second << '\n';
	}
	return os;
}
