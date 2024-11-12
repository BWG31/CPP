#ifndef HELPERS_H
# define HELPERS_H

#include <string>
#include <sstream>
#include <iostream>

typedef enum e_type
{
	INVALID = 0,
	CHAR,
	INTEGER,
	FLOAT,
	DOUBLE
}	t_type;

t_type	getType(std::string str);
bool	isChar(std::string str);
bool	isInt(std::string str);
bool	isFloat(std::string str);
bool	isDouble(std::string str);

float   convertToFloat(std::string str);
double  convertToDouble(std::string str);

#endif