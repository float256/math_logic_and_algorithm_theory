#include "../Entities/Literal.h"
#include <exception>
#include <stack>
#include <stdexcept>
#include <vector>
#include <cmath>

double Compute(const std::vector<Literal>& expressionInPostfixForm)
{
	std::stack<double> stack;
	for (auto& currLiteral : expressionInPostfixForm)
	{
		if (currLiteral.Type == LiteralType::Sigh)
		{
			double secondNumber = stack.top();
			stack.pop();

			double firstNumber = stack.top();
			stack.pop();

			if (currLiteral.Value == "+")
			{
				stack.push(firstNumber + secondNumber);
			}
			else if (currLiteral.Value == "-")
			{
				stack.push(firstNumber - secondNumber);
			}
			else if (currLiteral.Value == "*")
			{
				stack.push(firstNumber * secondNumber);
			}
			else if (currLiteral.Value == "/")
			{
				stack.push(firstNumber / secondNumber);
			}
			else if (currLiteral.Value == "^")
			{
				stack.push(std::pow(firstNumber, secondNumber));
			}
			else
			{
				throw std::invalid_argument("Incorrect sigh symbol.");
			}
		}
		else if (currLiteral.Type == LiteralType::Number)
		{
			double number = std::stod(currLiteral.Value);
			stack.push(number);
		}
		else
		{
			throw std::invalid_argument("In postfix notation, only signs and numbers are allowed.");
		}
	}
	return stack.top();
}