#include "UnaryBinaryOperationOnExpression.h"
#include "NullExpression.h"

UnaryBinaryOperationOnExpression::UnaryBinaryOperationOnExpression(UnaryBinaryOperator op_, Expression* expression_) :
    UnaryBinaryOperation(op_),
    expression(expression_)
{
    if(expression == nullptr)
    {
        expression = new NullExpression();
    }
}

UnaryBinaryOperationOnExpression::~UnaryBinaryOperationOnExpression()
{
    delete expression;
}

int UnaryBinaryOperationOnExpression::walkTree()
{
    return 0;
}

Expression* UnaryBinaryOperationOnExpression::getExpression()
{
    return expression;
}