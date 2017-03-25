#ifndef NULL_EXPRESSION_H
#define NULL_EXPRESSION_H

#include "Expression.h"

class NullExpression : public Expression
{
public:
    NullExpression();
    ~NullExpression();
    int walkTree();
};

#endif //NULL_EXPRESSION_H