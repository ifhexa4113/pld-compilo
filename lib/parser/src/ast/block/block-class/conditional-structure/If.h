#ifndef IF_H
#define IF_H

#include "ConditionalStructure.h"
#include "ast/expression/Expression.h"

class If: public ConditionalStructure
{
public:
    If(Block* block_, Expression* condition_);
    virtual ~If();
    virtual int walkTree();
};

#endif //IF_H
