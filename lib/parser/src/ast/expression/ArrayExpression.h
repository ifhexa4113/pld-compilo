#ifndef ARRAY_EXPRESSION_H
#define ARRAY_EXPRESSION_H

#include "LValueExpression.h"

class ArrayExpression : public LValueExpression
{
public:
    ArrayExpression(std::string name_, Expression* index_);
    ~ArrayExpression();
    int walkTree();

    void fillSymbolTable(SymbolTableStack& stack);
    void fillAstTrace(std::string& astTrace);
    bool checkReturnType(Type type, SymbolTableStack& stack){return false;};

protected:
    Expression* index;
};

#endif