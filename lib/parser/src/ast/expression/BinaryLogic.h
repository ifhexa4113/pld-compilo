#ifndef BINARY_LOGIC_H
#define BINARY_LOGIC_H

#include "Expression.h"

enum class LogicOperator
{
    EQUAL = 0,
    LESSER,
    GREATER,
    OR,
    AND,
    LESSER_EQUAL,
    GREATER_EQUAL,
    NOT_EQUAL
};

class BinaryLogic : public Expression
{
public:
    BinaryLogic(LogicOperator op_, Expression* lexpression_, Expression* rexpression_);
    virtual ~BinaryLogic();

    virtual int walkTree();

protected:
    LogicOperator op;
    Expression* lexpression;
    Expression* rexpression;
};

#endif