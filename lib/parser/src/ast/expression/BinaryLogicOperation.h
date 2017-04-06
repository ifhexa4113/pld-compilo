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

class BinaryLogicOperation : public Expression
{
public:
    BinaryLogicOperation(LogicOperator op_, Expression* lExpression_, Expression* rExpression_);
    ~BinaryLogicOperation();
    int walkTree();
    Expression* getRExpression();
    Expression* getLExpression();
    LogicOperator getOperator();

    void fillSymbolTable(SymbolTableStack& stack);
    Type getType(SymbolTableStack& stack);
    bool checkNonVoidType(SymbolTableStack& stack);
    void fillAstTrace(std::string& astTrace);
    bool checkReturnType(Type, SymbolTableStack&){return false;};

protected:
    LogicOperator op;
    Expression* lExpression;
    Expression* rExpression;
};

#endif