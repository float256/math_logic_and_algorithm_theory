#include <iostream>
#include <string>
#include "Parser/Parser.h"
#include "Entities/Literal.h"

int main() {
    std::string inputString;
    std::getline(std::cin, inputString);
	std::vector<Literal> expressionInLiteral;
	Parse(inputString, expressionInLiteral);
	if (IsCorrect(expressionInLiteral))
	{
		std::cout << "Correct" << std::endl;
	}
	else
	{
		std::cout << "Incorrect" << std::endl;
	}
    return 0;
}
