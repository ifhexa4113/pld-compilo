#include <iostream>
#include "VariableExpression.h"

VariableExpression::VariableExpression(std::string name_) :
    LValueExpression(name_)
{
    // Nothing else to do
}

VariableExpression::~VariableExpression()
{
    // Nothing else to do
}

int VariableExpression::walkTree()
{
    std::cout << name;
    return 0;
}

void VariableExpression::fillAstTrace(std::string& astTrace)
{
    astTrace += "VAR EXPR\n";
}