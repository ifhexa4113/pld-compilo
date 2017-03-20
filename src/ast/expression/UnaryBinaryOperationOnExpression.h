#ifndef UNARY_BINARY_OPERATION_ON_EXPRESSION_H
#define UNARY_BINARY_OPERATION_ON_EXPRESSION_H

#include "UnaryBinaryOperation.h"
#include "Expression.h"

class UnaryBinaryOperationOnExpression : public UnaryBinaryOperation
{
public:
    UnaryBinaryOperationOnExpression(UnaryBinaryOperator op_, Expression* expression_);
    ~UnaryBinaryOperationOnExpression();

    virtual int walkTree();

protected:
    Expression* expression;
};

#endif