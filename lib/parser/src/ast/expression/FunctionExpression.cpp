#include "FunctionExpression.h"

FunctionExpression::FunctionExpression(std::vector<Expression*> list_, std::string name_) :
        Expression(),
        parameters(list_),
        name(name_)

{

}

FunctionExpression::~FunctionExpression()
{
    for(auto expression : parameters)
        delete expression;
}

int FunctionExpression::walkTree()
{

}
