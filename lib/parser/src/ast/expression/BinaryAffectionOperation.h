#ifndef BINARY_AFFECTION_OPERATION_H
#define BINARY_AFFECTION_OPERATION_H

#include "Expression.h"
#include "LValueExpression.h"

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

class BinaryAffectionOperation : public Expression
{
public:
    BinaryAffectionOperation(AffectionOperator op_, LValueExpression* lvalue_, Expression* rExpression_);
    ~BinaryAffectionOperation();
    int walkTree();
    AffectionOperator getOperator();
    LValueExpression* getLValue();
    Expression* getRExpression();

    void fillSymbolTable(SymbolTableStack& stack);
    Type getType(SymbolTableStack& stack);

protected:
    AffectionOperator op;
    LValueExpression* lvalue;
    Expression* rExpression;
};

#endif