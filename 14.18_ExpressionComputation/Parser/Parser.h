//
// Created by user on 10.03.2021.
//

#ifndef INC_14_18_EXPRESSIONCOMPUTATION_PARSER_H
#define INC_14_18_EXPRESSIONCOMPUTATION_PARSER_H

#include "../Entities/Literal.h"
#include <string>
#include <vector>

void Parse(std::string expression, std::vector<Literal>& expressionInLiterals);
bool IsCorrect(const std::vector<Literal>& expressionInLiterals);

#endif //INC_14_18_EXPRESSIONCOMPUTATION_PARSER_H
