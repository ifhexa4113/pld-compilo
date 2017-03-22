#include <iostream>
#include "FunctionExpression.h"

FunctionExpression::FunctionExpression(std::string name_) :
    FunctionExpression(std::vector<Expression*>(), name_)
{
    // Nothing else to do
}

FunctionExpression::FunctionExpression(std::vector<Expression*> list_, std::string name_) :
    Expression(),
    name(name_),
    parameters(list_)
{
    // Nothing else to do
}

FunctionExpression::~FunctionExpression()
{
    for(auto expression : parameters)
    {
        delete expression;
    }
}

int FunctionExpression::walkTree()
{
    std::cout << "Calling function " << name << " with following parameters: ";
    for(auto param : parameters)
    {
        param->walkTree();
        std::cout << ", ";
    }
    std::cout << std::endl;
}
