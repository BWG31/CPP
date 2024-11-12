#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <cstdlib>
# include <cctype>
# include <stdexcept>
# include <limits>
# include <cmath>

# define MAX_PRECISION (20)

class ScalarConverter
{
	public:
		static void convert(std::string str);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &rhs);
};

typedef enum e_type
{
	INVALID = 0,
	CHAR,
	INTEGER,
	FLOAT,
	DOUBLE
}	t_type;

//	helpers.cpp
t_type	getType(std::string str);
bool	isChar(std::string str);
bool	isInt(std::string str);
bool	isFloat(std::string str);
bool	isDouble(std::string str);
float   convertToFloat(std::string str);
double  convertToDouble(std::string str);

//	print.cpp
void	printConversions(double value);
void	printCharConversion(double value);
void	printIntConversion(double value);
void	printFloatConversion(double value);
void	printDouble(double value);
std::string dynamicPrecision(double value);

#endif