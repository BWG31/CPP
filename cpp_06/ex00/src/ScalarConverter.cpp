#include "ScalarConverter.hpp"

//  ==========| CONSTRUCTORS |==========
ScalarConverter::ScalarConverter(){}

//  ============| METHODS |=============

void ScalarConverter::convert(std::string str)
{
	t_type	type = getType(str);
	std::cout << type << std::endl;

	double value;
	switch (type){
		case CHAR:
			value = str.front();
			break ;
		case INTEGER:
			value = std::atoi(str.c_str());
			break ;
		case FLOAT:
			value = convertToFloat(str);
			break ;
		case DOUBLE:
			value = convertToDouble(str);
			break ;
		default:
			std::cout << "Invalid input" << std::endl;
			return ;
	}
	printCharConversion(value);
	printIntConversion(value);
	printFloatConversion(value);
	printDouble(value);
}

void printCharConversion(double value)
{
	std::cout << "char: ";
	if (value >= 0 && value <= 127)
	{
		char c = static_cast<char>(value);
		if (!std::isprint(c))
			std::cout << "Non displayable";
		else
			std::cout << "'" << c << "'";
	}
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

void printDouble(double value)
{
	std::cout << "double: " << dynamicPrecision(value) << std::endl;
}

void printIntConversion(double value)
{
	long truncated_value = static_cast<long>(value);
	std::cout << "int: ";
	if (truncated_value >= std::numeric_limits<int>::min() && \
		truncated_value <= std::numeric_limits<int>::max())
		std::cout << static_cast<int>(truncated_value);
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

void printFloatConversion(double value)
{
	std::cout << "float: ";
	if (value == std::numeric_limits<float>::infinity())
		std::cout << "+inff";
	else if (value == -1 * std::numeric_limits<float>::infinity())
		std::cout << "-inff";
	else if (std::isnan(value))
		std::cout << "nanf";
	else if (value >= -std::numeric_limits<float>::max() && \
		value <= std::numeric_limits<float>::max())
		std::cout << dynamicPrecision(static_cast<float>(value)) << 'f';
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

std::string dynamicPrecision(double value)
{
	std::stringstream ss;
	ss << std::fixed << std::setprecision(MAX_PRECISION) << value;

	std::string str = ss.str();

	str.erase(str.find_last_not_of('0') + 1);
	if (str.back() == '.')
		str += '0';
	return (str);
}
