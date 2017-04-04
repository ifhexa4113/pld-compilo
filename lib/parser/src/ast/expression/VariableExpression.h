#ifndef VARIABLE_EXPRESSION_H
#define VARIABLE_EXPRESSION_H

#include <string>
#include "LValueExpression.h"

class VariableExpression : public LValueExpression
{
public:
    VariableExpression(std::string name_);
    ~VariableExpression();
    int walkTree();
    void fillAstTrace(std::string& astTrace);
    bool checkReturnType(Type type, SymbolTableStack& stack){return false;};
};

#endif