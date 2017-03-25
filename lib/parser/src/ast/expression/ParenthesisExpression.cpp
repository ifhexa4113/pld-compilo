#include "ParenthesisExpression.h"
#include "NullExpression.h"

Parenthesis::Parenthesis(Expression* expression_) :
    Expression(),
    expression(expression_)
{
    if(expression == nullptr)
    {
        expression = new NullExpression();
    }
}

Parenthesis::~Parenthesis()
{
    delete expression;
}

int Parenthesis::walkTree()
{
    return 0;
}
