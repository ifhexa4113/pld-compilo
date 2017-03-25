#ifndef IF_H
#define IF_H

#include <vector>
#include "ConditionalStructure.h"
#include "ast/AstNode.h"
#include "ast/expression/Expression.h"

class If: public ConditionalStructure
{
public:
    If(Expression* condition_);
    If(Expression* condition_, std::vector<AstNode*> children_);
    ~If();
    int walkTree();
};

#endif //IF_H
