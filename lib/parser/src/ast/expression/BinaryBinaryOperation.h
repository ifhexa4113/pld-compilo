#ifndef BINARY_BINARY_OPERATION_H
#define BINARY_BINARY_OPERATION_H

#include "Expression.h"

enum class BinaryBinaryOperator
{
    XOR = 0,
    OR,
    AND,
    LEFT_SHIFT,
    RIGHT_SHIFT
};

class BinaryBinaryOperation : public Expression
{
public:
    BinaryBinaryOperation(BinaryBinaryOperator op_, Expression* lexpression_, Expression* rexpression_);
    ~BinaryBinaryOperation();

    int walkTree();

protected:
    BinaryBinaryOperator op;
    Expression* lexpression;
    Expression* rexpression;
};

#endif