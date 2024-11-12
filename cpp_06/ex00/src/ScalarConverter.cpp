#include "ScalarConverter.hpp"

//  ==========| CONSTRUCTORS |==========

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

//  ===========| DESTRUCTOR |===========

ScalarConverter::~ScalarConverter() {}

//  =======| OPERATOR OVERLOADS |=======

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return *this;
}

//  ============| METHODS |=============

void ScalarConverter::convert(std::string str)
{
	double value;
	t_type	type = getType(str);

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
	printConversions(value);
}
