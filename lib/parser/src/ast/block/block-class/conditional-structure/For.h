#ifndef FOR_H
#define FOR_H

#include "ConditionalStructure.h"
#include "ast/expression/Expression.h"

class For: public ConditionalStructure
{
public:
    For(Block* block_, Expression* condition_, Expression* initialization_, Expression* increment_);
    virtual ~For();
    virtual int walkTree();

protected:
    Expression* initialization;
    Expression* increment;
};

#endif //FOR_H
