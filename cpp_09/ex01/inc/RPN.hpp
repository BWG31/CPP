#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <stdexcept>
# include <sstream>

class RPN
{
	public:
		RPN();
		RPN(const RPN &other);
		~RPN();

		RPN &operator=(const RPN &rhs);

		int calculate(char *arg);

	private:
	
		bool isValidNumber(std::string &str);
		bool isValidOperator(std::string &str);
		int	convertToNum(std::string &str);
		int performOperation(int left, int right, const std::string &op);
		int safeDivide(int left, int right);
};

#endif