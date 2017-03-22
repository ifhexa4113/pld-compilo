#ifndef FOR_H
#define FOR_H

#include "ConditionalStructure.h"
#include "ast/expression/Expression.h"

class For: public ConditionalStructure
{
public:
    For(Expression* condition_, Expression* initialization_, Expression* increment_);
    ~For();
    int walkTree();

protected:
    Expression* initialization;
    Expression* increment;
};

#endif //FOR_H
