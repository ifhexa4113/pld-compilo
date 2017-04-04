#ifndef UNARY_BINARY_OPERATION_ON_VARIABLE_H
#define UNARY_BINARY_OPERATION_ON_VARIABLE_H

#include "UnaryBinaryOperation.h"
#include "LValueExpression.h"

class UnaryBinaryOperationOnVariable : public UnaryBinaryOperation
{
public:
    UnaryBinaryOperationOnVariable(UnaryBinaryOperator op_, LValueExpression* variable_);
    ~UnaryBinaryOperationOnVariable();
    int walkTree();
    LValueExpression* getVariable();

    void fillSymbolTable(SymbolTableStack& stack);
    Type getType(SymbolTableStack& stack);
    bool checkNonVoidType(SymbolTableStack& stack);
    void fillAstTrace(std::string& astTrace);

protected:
    LValueExpression* variable;
};

#endif