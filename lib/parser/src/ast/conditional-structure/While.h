#ifndef WHILE_H
#define WHILE_H

#include "ConditionalStructure.h"
#include "ast/expression/Expression.h"

class While: public ConditionalStructure
{
public:
    While(Expression* condition_);
    ~While();
    int walkTree();
};

#endif //WHILE_H
