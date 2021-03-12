//
// Created by user on 10.03.2021.
//

#include "Parser.h"
#include "../Entities/Literal.h"
#include <string>
#include <vector>

// Private

bool IsCorrectBrackets(const std::vector<Literal>& expressionInLiterals)
{
	int currLevel = 0;
	for (auto& currLiteral : expressionInLiterals)
	{
		if (currLiteral.Type == LiteralType::Bracket)
		{
			if (currLiteral.Value == "(")
			{
				currLevel++;
			}
			else if (currLiteral.Value == ")")
			{
				currLevel--;
				if (currLevel < 0)
				{
					return false;
				}
			}
		}
	}
	if (currLevel == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool IsCorrectNumbersAndDigitsArrangement(const std::vector<Literal>& expressionInLiterals)
{
	bool isEmpty = expressionInLiterals.empty();
	bool isIncorrectExpressionWithOneSymbol = (expressionInLiterals.size() == 1) && (expressionInLiterals[0].Type == LiteralType::Sigh);
	bool isIncorrectFirstSymbol = (expressionInLiterals.size() > 1) && (expressionInLiterals[0].Type == LiteralType::Sigh)
		&& (expressionInLiterals[0].Value != "+") && (expressionInLiterals[0].Value != "-");
	if (isIncorrectExpressionWithOneSymbol || isEmpty || isIncorrectFirstSymbol)
	{
		return false;
	}

	LiteralType previousLiteralType;
	for (int i = 0; i < expressionInLiterals.size(); ++i)
	{
		if (expressionInLiterals[i].Type == LiteralType::Bracket)
		{
			int bracketStartBodyIdx = (i + 1), bracketEndBodyIdx;
			int currLevel = 1;
			i++;
			while (currLevel > 0)
			{
				if (expressionInLiterals[i].Value == "(")
				{
					currLevel++;
				}
				else if (expressionInLiterals[i].Value == ")")
				{
					currLevel--;
				}
				i++;
			}
			i--;
			bracketEndBodyIdx = i;

			auto bracketStartBodyIterator = expressionInLiterals.begin() + bracketStartBodyIdx;
			auto bracketEndBodyIterator = expressionInLiterals.begin() + bracketEndBodyIdx;
			std::vector<Literal> bracketBodyExpressionInLiterals = std::vector<Literal>(bracketStartBodyIterator, bracketEndBodyIterator);
			if (!IsCorrectNumbersAndDigitsArrangement(bracketBodyExpressionInLiterals))
			{
				return false;
			}
		}
		else if ((i != 0) && (expressionInLiterals[i].Type == previousLiteralType))
		{
			return false;
		}
		previousLiteralType = expressionInLiterals[i].Type;
	}
	if (expressionInLiterals[expressionInLiterals.size() - 1].Type == LiteralType::Sigh)
	{
		return false;
	}
	else
	{
		return true;
	}
}

// Public

void Parse(std::string expression, std::vector<Literal>& expressionInLiterals)
{
	std::string number;
	expressionInLiterals.clear();
	for (auto currSymbol : expression)
	{
		if (isdigit(currSymbol) || (currSymbol == '.'))
		{
			number += currSymbol;
		}
		else if (!number.empty())
		{
			expressionInLiterals.emplace_back(Literal(number, LiteralType::Number));
			number.clear();
		}
		if ((currSymbol == '+') || (currSymbol == '-') || (currSymbol == '*') || (currSymbol == '/'))
		{
			expressionInLiterals.emplace_back(Literal(std::string(1, currSymbol), LiteralType::Sigh));
		}
		if ((currSymbol == '(') || (currSymbol == ')'))
		{
			expressionInLiterals.emplace_back(Literal(std::string(1, currSymbol), LiteralType::Bracket));
		}
	}
	if (!number.empty())
	{
		expressionInLiterals.emplace_back(Literal(number, LiteralType::Number));
	}
}

bool IsCorrect(const std::vector<Literal>& expressionInLiterals)
{
	if (!IsCorrectBrackets(expressionInLiterals))
	{
		return false;
	}
	return IsCorrectNumbersAndDigitsArrangement(expressionInLiterals);
}