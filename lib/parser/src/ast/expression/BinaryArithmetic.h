#ifndef BINARY_ARITHMETIC_H
#define BINARY_ARITHMETIC_H

#include "Expression.h"

enum class ArithmeticOperator
{
    PLUS = 0,
    MINUS,
    MUL,
    DIV,
    MOD
};

class BinaryArithmetic : public Expression
{
public:
    BinaryArithmetic(ArithmeticOperator op_, Expression* lexpression_, Expression* rexpression_);
    ~BinaryArithmetic();

    int walkTree();

protected:
    ArithmeticOperator op;
    Expression* lexpression;
    Expression* rexpression;
};

#endif