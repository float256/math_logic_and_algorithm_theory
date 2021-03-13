#ifndef INC_14_18_EXPRESSIONCOMPUTATION_CALCULATOR_H
#define INC_14_18_EXPRESSIONCOMPUTATION_CALCULATOR_H

#include <vector>
#include "../Entities/Literal.h"

double Compute(const std::vector<Literal>& expressionInPostfixForm);

#endif //INC_14_18_EXPRESSIONCOMPUTATION_CALCULATOR_H
