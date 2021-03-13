#include "Calculator/Calculator.h"
#include "Convertor/Convertor.h"
#include "Entities/Literal.h"
#include "Parser/Parser.h"
#include <iostream>
#include <limits>
#include <string>

int main()
{
	std::string inputString;
	std::getline(std::cin, inputString);
	std::vector<Literal> expressionInInfixForm;

	try
	{
		Parse(inputString, expressionInInfixForm);
	}
	catch (std::exception& exception)
	{
		std::cout << "Error while parsing an expression.";
		return 1;
	}

	if (IsCorrect(expressionInInfixForm))
	{
		std::vector<Literal> expressionInPostfixForm = ConvertExpressionToPostfixForm(expressionInInfixForm);
		std::cout.precision(std::numeric_limits<double>::max_digits10);
		std::cout << Compute(expressionInPostfixForm) << std::endl;
		return 0;
	}
	else
	{
		std::cout << "Incorrect expression" << std::endl;
		return 1;
	}
}
