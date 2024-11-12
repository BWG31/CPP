#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include "helpers.h"

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
};

void	printCharConversion(double value);
void	printIntConversion(double value);
void	printFloatConversion(double value);
void	printDouble(double value);

std::string dynamicPrecision(double value);

#endif