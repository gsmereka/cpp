#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <stdexcept>

class RPN
{
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		int evaluate(const std::string &expression);

	private:
		std::stack<int> operands;

		bool isOperator(char c);
		int performOperation(char operation, int operand1, int operand2);
};

#endif // RPN_HPP
