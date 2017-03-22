#ifndef CONDITIONALSTRUCTURE_H
#define CONDITIONALSTRUCTURE_H

#include "AstNode.h"
#include "ast/expression/Expression.h"

class ConditionalStructure: public AstNode
{
public:
    ConditionalStructure(Expression* condition_);
    virtual ~ConditionalStructure();
    virtual int walkTree();

protected:
    Expression* condition;
};

#endif //CONDITIONALSTRUCTURE_H
