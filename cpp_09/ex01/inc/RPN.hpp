#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <stdexcept>

class RPN
{
	enum{
		OPERATOR,
		NUM
	};
	public:
		RPN();
		RPN(const RPN &other);
		RPN(char **argv);
		~RPN();

		RPN &operator=(const RPN &rhs);

		int calculate(void);

		std::stack<std::string> getStack() const;
	private:
		std::stack<std::string>	stack_;
	
		bool isValidNumber(std::string &str);
		bool isValidOperator(std::string &str);
		int	convertToNum(std::string &str);
		int performOperation(int left, int right, const std::string &operator);
};

#endif