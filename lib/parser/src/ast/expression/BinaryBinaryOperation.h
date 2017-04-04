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
    BinaryBinaryOperation(BinaryBinaryOperator op_, Expression* lExpression_, Expression* rExpression_);
    ~BinaryBinaryOperation();
    int walkTree();
    Expression* getRExpression();
    Expression* getLExpression();
    BinaryBinaryOperator getOperator();

    void fillSymbolTable(SymbolTableStack& stack);
    Type getType(SymbolTableStack& stack);
    bool checkNonVoidType(SymbolTableStack& stack);
    void fillAstTrace(std::string& astTrace);

protected:
    BinaryBinaryOperator op;
    Expression* lExpression;
    Expression* rExpression;
};

#endif