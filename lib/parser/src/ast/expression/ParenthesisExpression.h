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

protected:
    Expression* expression;
};

#endif