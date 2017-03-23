
#ifndef CONDITIONALSTRUCTURE_H
#define CONDITIONALSTRUCTURE_H


#include "ast/block/block-class/BlockClass.h"
#include "ast/expression/Expression.h"

class ConditionalStructure: public BlockClass
{
public:
    ConditionalStructure(Block* block_, Expression* condition_);
    virtual ~ConditionalStructure();

    virtual int walkTree();

protected:
    Expression* condition;
};

#endif //CONDITIONALSTRUCTURE_H
