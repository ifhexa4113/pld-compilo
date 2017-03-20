#include "UnaryBinaryOperationOnExpression.h"

UnaryBinaryOperationOnExpression::UnaryBinaryOperationOnExpression(UnaryBinaryOperator op_, Expression* expression_) :
    UnaryBinaryOperation(op_),
    expression(expression_)
{

}

UnaryBinaryOperationOnExpression::~UnaryBinaryOperationOnExpression()
{
    delete expression;
}

int UnaryBinaryOperationOnExpression::walkTree()
{
    
}