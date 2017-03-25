#ifndef VARIABLE_DEFINITION_H
#define VARIABLE_DEFINITION_H

#include <string>
#include "Definition.h"
#include "ast/expression/Expression.h"

class VariableDefinition : public Definition
{
public:
    VariableDefinition(std::string name_, Expression* rExpression_);
    ~VariableDefinition();
    int walkTree();
    Expression* getRExpression();

protected:
    Expression* rExpression;
};

#endif