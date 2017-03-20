#ifndef BINARY_AFFECTION_H
#define BINARY_AFFECTION_H

#include "Expression.h"

enum class AffectionOperator
{
    EQUAL = 0,
    PLUS_EQUAL,
    MINUS_EQUAL,
    MUL_EQUAL,
    DIV_EQUAL,
    MOD_EQUAL,
    XOR_EQUAL,
    OR_EQUAL,
    AND_EQUAL
};

class BinaryAffection : public Expression
{
public:
    BinaryAffection(AffectionOperator op_, Expression* lexpression_, Expression* rexpression_);
    ~BinaryAffection();

    int walkTree();

protected:
    AffectionOperator op;
    Expression* lexpression;
    Expression* rexpression;

};

#endif