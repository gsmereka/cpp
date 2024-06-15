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

		double	evaluate(const std::string &expression);

	private:
		std::stack<double>	operands;

		bool	isOperator(char c);
		double	performOperation(char operation, double operand1, double operand2);
};

#endif // RPN_HPP
