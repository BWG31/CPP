#include "BitcoinExchange.hpp"

//  ==========| CONSTRUCTORS |==========
BitcoinExchange::BitcoinExchange()
{
    //  DEFAULT
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

//  ===========| DESTRUCTOR |===========
BitcoinExchange::~BitcoinExchange()
{
    //  DEFAULT
}

//  =======| OPERATOR OVERLOADS |=======
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    if (&rhs == this)
        return *this;
    data_ = rhs.getData();
}

//  ============| GETTERS |=============

const t_data &BitcoinExchange::getData() const { return data_; }

//  ============| METHODS |=============

bool BitcoinExchange::parseData(std::ifstream &input)
{
    std::string key, value_str;
    double value = 0;
    int line = 1;
    bool noErrors = true;

    try
    {
        checkHeader(input);
        while (input.good())
        {
            line ++;
            getline(input, key, ','); // VALIDATE?
            getline(input, value_str);
            value = convertToDouble(value_str); // VALIDATE?
            data_.insert(std::pair(key, value));
        }
        return true;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error (Line " << line << "): " << e.what() << std::endl;
    }
    return false;
}

void BitcoinExchange::checkHeader(std::ifstream &input)
{
    std::string first_line;
    getline(input, first_line);
    if (first_line.compare(CSV_HEADER_))
        throw std::invalid_argument("Invalid csv header:" + first_line + "\texpected: " + CSV_HEADER_);
}

//  ============| STATIC METHODS |=============

double  BitcoinExchange::convertToDouble(std::string str)
{
	const char	*c_str = str.c_str();
	char 		*end = NULL;
	double		value;

    errno = 0;
	value = std::strtod(c_str, &end);
	if (c_str == end)
		throw std::invalid_argument("Unable to convert to double: " + str);
	if (errno == ERANGE)
		throw std::invalid_argument("Out of double range: " + str);
	if (end && *end != '\0')
		throw std::invalid_argument("Invalid trailing character(s): " + str);
	return (value);
}


//  ========| VIRTUAL METHODS |=========
