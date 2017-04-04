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

class BinaryArithmeticOperation : public Expression
{
public:
    BinaryArithmeticOperation(ArithmeticOperator op_, Expression* lExpression_, Expression* rExpression_);
    ~BinaryArithmeticOperation();
    int walkTree();
    Expression* getRExpression();
    Expression* getLExpression();
    ArithmeticOperator getOperator();

    void fillSymbolTable(SymbolTableStack& stack);
    Type getType(SymbolTableStack& stack);
    bool checkNonVoidType(SymbolTableStack& stack);
    void fillAstTrace(std::string& astTrace);
    bool checkReturnType(Type, SymbolTableStack&){return false;};

protected:
    ArithmeticOperator op;
    Expression* lExpression;
    Expression* rExpression;
};

#endif