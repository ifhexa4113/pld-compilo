#ifndef UNARY_BINARY_OPERATION_ON_EXPRESSION_H
#define UNARY_BINARY_OPERATION_ON_EXPRESSION_H

#include "UnaryBinaryOperation.h"
#include "Expression.h"

class UnaryBinaryOperationOnExpression : public UnaryBinaryOperation
{
public:
    UnaryBinaryOperationOnExpression(UnaryBinaryOperator op_, Expression* expression_);
    ~UnaryBinaryOperationOnExpression();
    int walkTree();
    Expression* getExpression();

protected:
    Expression* expression;
};

#endif