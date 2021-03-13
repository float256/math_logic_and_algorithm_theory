#ifndef INC_14_18_EXPRESSIONCOMPUTATION_CONVERTOR_H
#define INC_14_18_EXPRESSIONCOMPUTATION_CONVERTOR_H

#include "../Entities/Literal.h"
#include <map>
#include <vector>

std::vector<Literal> ConvertExpressionToPostfixForm(const std::vector<Literal>& expressionInInfixForm);

#endif //INC_14_18_EXPRESSIONCOMPUTATION_CONVERTOR_H
