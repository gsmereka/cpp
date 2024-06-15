#include "../headers/RPN.hpp"
#include <sstream>
#include <cctype>

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        this->operands = other.operands;
    }
    return *this;
}

RPN::~RPN() {}

int RPN::evaluate(const std::string &expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token.length() == 1 && isOperator(token[0])) {
            if (operands.size() < 2) {
                throw std::runtime_error("Invalid expression");
            }
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            int result = performOperation(token[0], operand1, operand2);
            operands.push(result);
        } else if (std::isdigit(token[0])) {
            operands.push(token[0] - '0');
        } else {
            throw std::runtime_error("Invalid character in expression");
        }
    }

    if (operands.size() != 1) {
        throw std::runtime_error("Invalid expression");
    }

    return operands.top();
}

bool RPN::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::performOperation(char operation, int operand1, int operand2) {
    switch (operation) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                throw std::runtime_error("Division by zero");
            }
            return operand1 / operand2;
        default:
            throw std::runtime_error("Unknown operator");
    }
}
