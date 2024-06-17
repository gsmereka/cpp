#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <stdexcept>
# define RED "\x1b[38;5;88m"
# define GREEN "\x1b[38;5;40m"
# define BLUE "\x1b[38;5;25m"
# define YELLOW "\x1b[38;5;220m"
# define ORANGE	"\033[0;38;5;166m"
# define RES "\x1b[0m"

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

bool	isValidValue(const std::string &valueStr);

#endif
