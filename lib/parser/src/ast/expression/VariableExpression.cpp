#include <iostream>

#include "VariableExpression.h"

VariableExpression::VariableExpression(std::string name_) :
    LValueExpression(name_)
{

}

int VariableExpression::walkTree()
{
    std::cout << name;
    return 0;
}

