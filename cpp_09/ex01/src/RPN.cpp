#include "RPN.hpp"

//  ==========| CONSTRUCTORS |==========
RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

//  ===========| DESTRUCTOR |===========
RPN::~RPN() {}

//  =======| OPERATOR OVERLOADS |=======
RPN &RPN::operator=(const RPN &rhs)
{
	(void)rhs;
	return *this;
}

//  ============| METHODS |=============

int RPN::calculate(char *arg)
{
	std::string input(arg);
	std::stringstream ss(input);
	std::string	str;
	std::stack<int> nums;

	while (getline(ss, str, ' '))
	{
		if (isValidNumber(str))
			nums.push(convertToNum(str));
		else if (isValidOperator(str))
		{
			if (nums.size() < 2)
				throw std::runtime_error("Expected number but found operator");
			int right = nums.top();
			nums.pop();
			int left = nums.top();
			nums.pop();
			nums.push(performOperation(left, right, str));
		}
		else
			throw std::runtime_error("Invalid argument: " + str);
	}
	if (nums.size() != 1)
		throw std::runtime_error("Last argument must be an operator");
	return nums.top();
}

int RPN::performOperation(int left, int right, const std::string &op)
{
	if (op == "+")
		return (left + right);
	if (op == "-")
		return (left - right);
	if (op == "*")
		return (left * right);
	if (op == "/")
		return (left * right);
	throw std::runtime_error("Invalid operand in performOperation");
}

bool RPN::isValidNumber(std::string &str)
{
	return (str.size() == 1 && str.find_first_not_of("0123456789") == std::string::npos);
}

bool RPN::isValidOperator(std::string &str)
{
	return (str.size() == 1 && str.find_first_not_of("+-/*") == std::string::npos);
}

int RPN::convertToNum(std::string &str)
{
	return (str[0] - '0');
}
