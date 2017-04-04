#ifndef PARENTHESIS_H
#define PARENTHESIS_H

#include "Expression.h"

class ParenthesisExpression : public Expression
{
public:
    ParenthesisExpression(Expression* expression_);
    ~ParenthesisExpression();
    int walkTree();

    void fillSymbolTable(SymbolTableStack& stack);
    Type getType(SymbolTableStack& stack);
    bool checkNonVoidType(SymbolTableStack& stack);
    void fillAstTrace(std::string& astTrace);
    bool checkReturnType(Type, SymbolTableStack&){return false;};

protected:
    Expression* expression;
};

#endif