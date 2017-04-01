#ifndef PARENTHESIS_H
#define PARENTHESIS_H

#include "Expression.h"

class ParenthesisExpression : public Expression
{
public:
    ParenthesisExpression(Expression* expression_);
    ~ParenthesisExpression();
    int walkTree();

    Expression* getExpression() const;

protected:
    Expression* expression;
};

#endif