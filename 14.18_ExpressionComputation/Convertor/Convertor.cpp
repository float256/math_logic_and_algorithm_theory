#include "Convertor.h"
#include "../Entities/Literal.h"
#include <stack>
#include <vector>

std::vector<Literal> ConvertExpressionToPostfixForm(const std::vector<Literal>& expressionInInfixForm)
{
	std::map<char, int> OperationPriority = {
		{ '+', 1 },
		{ '-', 1 },
		{ '*', 2 },
		{ '/', 2 },
		{'^', 3}
	};

	std::vector<Literal> expressionInPostfixForm;
	std::stack<Literal> stack;

	for (auto& currLiteral : expressionInInfixForm)
	{
		if (currLiteral.Type == LiteralType::Number)
		{
			expressionInPostfixForm.push_back(currLiteral);
		}
		else if (currLiteral.Type == LiteralType::Sigh)
		{
			if (stack.empty() || (stack.top().Value == "("))
			{
				stack.push(currLiteral);
			}
			else if (OperationPriority[currLiteral.Value[0]] > OperationPriority[stack.top().Value[0]])
			{
				stack.push(currLiteral);
			}
			else if (OperationPriority[currLiteral.Value[0]] <= OperationPriority[stack.top().Value[0]])
			{
				while (!stack.empty()
					&& (OperationPriority[currLiteral.Value[0]] <= OperationPriority[stack.top().Value[0]])
					&& (stack.top().Value != "("))
				{
					expressionInPostfixForm.push_back(stack.top());
					stack.pop();
				}
				stack.push(currLiteral);
			}
		}
		else if (currLiteral.Type == LiteralType::Bracket)
		{
			if (currLiteral.Value == "(")
			{
				stack.push(currLiteral);
			}
			else if (currLiteral.Value == ")")
			{
				while (stack.top().Value != "(")
				{
					expressionInPostfixForm.push_back(stack.top());
					stack.pop();
				}
				stack.pop();
			}
		}
	}
	while (!stack.empty())
	{
		expressionInPostfixForm.push_back(stack.top());
		stack.pop();
	}
	return expressionInPostfixForm;
}
