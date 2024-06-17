#include "../headers/RPN.hpp"
#include <sstream>
#include <cctype>

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN	&RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->operands = other.operands;
	}
	return *this;
}

RPN::~RPN() {}

double	RPN::evaluate(const std::string &expression)
{
	std::istringstream splitedStream(expression);
	std::string token;

	while (splitedStream >> token)
	{
		if (token.length() == 1 && isOperator(token[0]))
		{
			if (operands.size() < 2)
			{
				throw std::runtime_error("Invalid expression");
			}
			double operand2 = operands.top();
			operands.pop();
			double operand1 = operands.top();
			operands.pop();
			double result = performOperation(token[0], operand1, operand2);
			operands.push(result);
		}
		else if (isValidValue(token))
		{
			if (token[0] == '-')
				operands.push((token[1] - '0') * -1);
			else
				operands.push(token[0] - '0');
		}
		else
		{
			throw std::runtime_error("Invalid character in expression");
		}
	}

	if (operands.size() != 1)
	{
		throw std::runtime_error("Invalid expression");
	}

	return operands.top();
}

bool	RPN::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

double RPN::performOperation(char operation, double operand1, double operand2)
{
	switch (operation)
	{
		case '+':
			return operand1 + operand2;
		case '-':
			return operand1 - operand2;
		case '*':
			return operand1 * operand2;
		case '/':
			if (operand2 == 0)
			{
				throw std::runtime_error("Division by zero");
			}
			return operand1 / operand2;
		default:
			throw std::runtime_error("Unknown operator");
	}
}

bool	isValidValue(const std::string &valueStr)
{
	if (valueStr[0] == '-' && std::isdigit(valueStr[1])  && valueStr.length() == 2)
	{
		return true;
	}
	if (std::isdigit(valueStr[0]) && valueStr.length() == 1)
	{
		return true;
	}
	return false;
}
