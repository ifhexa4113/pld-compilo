#ifndef PARENTHESIS_H
#define PARENTHESIS_H

#include "Expression.h"

class Parenthesis : public Expression
{
public:
    Parenthesis(Expression* expression_);
    ~Parenthesis();
    int walkTree();

protected:
    Expression* expression;
};

#endif