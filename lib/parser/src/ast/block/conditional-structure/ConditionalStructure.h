#ifndef CONDITIONAL_STRUCTURE_H
#define CONDITIONAL_STRUCTURE_H

#include <vector>
#include "ast/AstNode.h"
#include "ast/block/Block.h"
#include "ast/expression/Expression.h"

class ConditionalStructure: public Block
{
public:
    ConditionalStructure(Expression* condition_);
    ConditionalStructure(Expression* condition_, std::vector<AstNode*> children_);
    virtual ~ConditionalStructure();
    virtual int walkTree();
    Expression* getCondition();

protected:
    Expression* condition;
};

#endif //CONDITIONAL_STRUCTURE_H
