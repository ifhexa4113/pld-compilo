#ifndef WHILE_H
#define WHILE_H

#include <vector>
#include "ConditionalStructure.h"
#include "ast/AstNode.h"
#include "ast/expression/Expression.h"

class While: public ConditionalStructure
{
public:
    While(Expression* condition_);
    While(Expression* condition_, std::vector<AstNode*> children_);
    ~While();
    int walkTree();
};

#endif //WHILE_H
