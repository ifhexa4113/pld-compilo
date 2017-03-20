#ifndef UNARY_BINARY_OPERATION_ON_VARIABLE_H
#define UNARY_BINARY_OPERATION_ON_VARIABLE_H

#include "UnaryBinaryOperation.h"
#include "VariableExpression.h"

class UnaryBinaryOperationOnVariable : public UnaryBinaryOperation
{
public:
    UnaryBinaryOperationOnVariable(UnaryBinaryOperator op_, VariableExpression* variable_);
    ~UnaryBinaryOperationOnVariable();

    virtual int walkTree();

protected:
    VariableExpression* variable;
};

#endif