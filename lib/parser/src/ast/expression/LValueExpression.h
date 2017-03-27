#ifndef L_VALUE_EXPRESSION_H
#define L_VALUE_EXPRESSION_H

#include <string>
#include "Expression.h"

class LValueExpression : public Expression
{
public:
    LValueExpression(std::string name_);
    virtual ~LValueExpression();

    virtual int walkTree() = 0;
    std::string getName();

    virtual void fillSymbolTable(SymbolTableStack& stack);

protected:
    std::string name;
};

#endif