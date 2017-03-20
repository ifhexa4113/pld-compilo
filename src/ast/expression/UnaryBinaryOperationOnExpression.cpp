#include "UnaryBinaryOperationOnExpression.h"

UnaryBinaryOperationOnExpression::UnaryBinaryOperationOnExpression(UnaryBinaryOperator op, Expression* expression) :
    UnaryBinaryOperator(op),
    this->expression(expression)
{

}

UnaryBinaryOperationOnExpression::~UnaryBinaryOperationOnExpression()
{
    delete expression;
}

int UnaryBinaryOperationOnExpression::walkTree()
{
    
}