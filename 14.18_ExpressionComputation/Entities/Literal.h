#ifndef INC_14_18_EXPRESSIONCOMPUTATION_LITERAL_H
#define INC_14_18_EXPRESSIONCOMPUTATION_LITERAL_H

#include <string>

enum class LiteralType
{
	Sigh,
	Number,
	Bracket
};

class Literal
{
public:
	std::string Value;
	LiteralType Type;

	Literal(std::string value, LiteralType type): Value(value), Type(type) {}
	Literal(): Value(), Type() {}
};

#endif //INC_14_18_EXPRESSIONCOMPUTATION_LITERAL_H
