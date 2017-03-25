#include <iostream>
#include "FunctionExpression.h"

FunctionExpression::FunctionExpression(std::string name_) :
    FunctionExpression(name_, std::vector<Expression*>())
{
    // Nothing else to do
}

FunctionExpression::FunctionExpression(std::string name_, std::vector<Expression*> parameters_) :
    Expression(),
    name(name_),
    parameters(parameters_)
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
    return 0;
}

std::string FunctionExpression::getName()
{
    return name;
}

std::vector<Expression *> FunctionExpression::getParameters()
{
    return parameters;
}