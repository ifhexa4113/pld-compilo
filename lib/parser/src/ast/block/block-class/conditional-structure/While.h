#ifndef WHILE_H
#define WHILE_H

#include "ConditionalStructure.h"
#include "ast/expression/Expression.h"

class While: public ConditionalStructure
{
public:
    While(Block* block_, Expression* condition_);
    virtual ~While();
    virtual int walkTree();
};

#endif //WHILE_H
