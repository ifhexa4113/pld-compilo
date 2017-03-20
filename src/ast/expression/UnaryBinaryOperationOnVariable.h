#ifndef UNARY_BINARY_OPERATION_ON_VARIABLE_H
#define UNARY_BINARY_OPERATION_ON_VARIABLE_H

#include "UnaryBinaryOperation.h"
#include "Variable.h"

class UnaryBinaryOperationOnVariable : public UnaryBinaryOperation
{
public:
    UnaryBinaryOperationOnVariable(UnaryBinaryOperator op, Variable* variable);
    ~UnaryBinaryOperationOnVariable();

    virtual int walkTree();

protected:
    Variable* variable;
};

#endif