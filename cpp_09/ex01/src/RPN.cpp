#include "RPN.hpp"

//  ==========| CONSTRUCTORS |==========
RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN::RPN(char **argv)
{
	for (std::string str; argv; argv++)
	{
		str = std::string(*argv);
		if (str.size() == 1 || isValidNumber(str) || isValidOperator(str))
			stack_.push(str);
		else
			throw std::invalid_argument("Invalid argument : " + str);
	}
}

//  ===========| DESTRUCTOR |===========
RPN::~RPN() {}

//  =======| OPERATOR OVERLOADS |=======
RPN &RPN::operator=(const RPN &rhs)
{
	this->stack_ = rhs.getStack();
	return *this;
}

//  ============| METHODS |=============

int RPN::calculate()
{
	std::stack<int> nums;

	while (stack_.size())
	{
		if (isValidNumber(stack_.top()))
			nums.push(convertToNum(stack_.top()));
		else if (isValidOperator(stack_.top()))
		{
			if (!nums.size() < 2)
				throw std::runtime_error("Expected number but found operator");
			while (nums.size())
			{
				int left = nums.top();
				nums.pop();
				int right = nums.top();
				nums.pop();
				nums.push(performOperation(left, right, stack_.top()));
			}
			nums.empty();
		}
		else
			throw std::runtime_error("Invalid element in stack");
		stack_.pop();
	}
	if (nums.size() != 1)
		throw std::runtime_error("Last argument must be an operator");
	return nums.top();
}

int RPN::performOperation(int left, int right, const std::string &operator)
{
	// TODO
}

std::stack<std::string> RPN::getStack() const
{
	return stack_;
}

bool RPN::isValidNumber(std::string &str)
{
	return (str.find_first_not_of("0123456789") == std::string::npos);
}

bool RPN::isValidOperator(std::string &str)
{
	return (str.find_first_not_of("+-/*") == std::string::npos);
}

int RPN::convertToNum(std::string &str)
{
	return (str[0] - '0');
}
