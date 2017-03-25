#ifndef FOR_H
#define FOR_H

#include <vector>
#include "ConditionalStructure.h"
#include "ast/AstNode.h"
#include "ast/expression/Expression.h"

class For: public ConditionalStructure
{
public:
    For(Expression* condition_, Expression* initialization_, Expression* increment_);
    For(Expression* condition_, Expression* initialization_, Expression* increment_, std::vector<AstNode*> children_);
    ~For();
    int walkTree();
    Expression* getInitialization();
    Expression* getIncrement();

protected:
    Expression* initialization;
    Expression* increment;
};

#endif //FOR_H
