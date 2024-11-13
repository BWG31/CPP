#include "ScalarConverter.hpp"

t_type	getType(std::string str)
{
	if (isChar(str))
		return (CHAR);
	if (isInt(str))
		return (INTEGER);
    if (isFloat(str))
        return (FLOAT);
    if (isDouble(str))
        return (DOUBLE);
    return (INVALID);
}

bool    isChar(std::string str)
{
    return (str.size() == 1 && !std::isdigit(str[0]));
}

bool    isInt(std::string str)
{
    int value;
    std::stringstream ss(str);

    if (ss >> value)
        return (ss.eof());
    else
        return (false);
}

bool    isFloat(std::string str)
{
    try {
        convertToFloat(str);
    } catch (std::invalid_argument &e){
        return (false);
    }
    return (true);
}

bool    isDouble(std::string str)
{
    try {
        convertToDouble(str);
    } catch (std::invalid_argument &e){
        return (false);
    }
    return (true);
}

float   convertToFloat(std::string str)
{
	const char	*c_str = str.c_str();
	char 		*end = NULL;
	double		value;

	value = std::strtod(c_str, &end);
	if (c_str == end)
		throw std::invalid_argument("Unable to convert to float");
	if (errno == ERANGE)
		throw std::invalid_argument("Out of double range");
	std::string suffix(end);    
	if (!end || *end != 'f' || suffix.length() > 1)
		throw std::invalid_argument("No trailing f");
    if (value != std::numeric_limits<float>::infinity() && \
        value != -std::numeric_limits<float>::infinity())
    {
        if (value < -std::numeric_limits<float>::max())
            throw std::invalid_argument("Below -(float max)");
        if (value > std::numeric_limits<float>::max())
            throw std::invalid_argument("Above float max");
    }
	return (static_cast<float>(value));
}

double  convertToDouble(std::string str)
{
	const char	*c_str = str.c_str();
	char 		*end = NULL;
	double		value;

	value = std::strtod(c_str, &end);
	if (c_str == end)
		throw std::invalid_argument("Unable to convert to double");
	if (errno == ERANGE)
		throw std::invalid_argument("Out of double range");
	if (end && *end != '\0')
		throw std::invalid_argument("Invalid trailing character(s)");
	return (value);
}
