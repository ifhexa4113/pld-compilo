#include "ParenthesisExpression.h"
#include "NullExpression.h"

ParenthesisExpression::ParenthesisExpression(Expression* expression_) :
    Expression(),
    expression(expression_)
{
    if(expression == nullptr)
    {
        expression = new NullExpression();
    }
}

ParenthesisExpression::~ParenthesisExpression()
{
    delete expression;
}

int ParenthesisExpression::walkTree()
{
    return 0;
}
