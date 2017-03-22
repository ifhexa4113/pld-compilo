#ifndef IF_H
#define IF_H

#include "ConditionalStructure.h"
#include "ast/expression/Expression.h"

class If: public ConditionalStructure
{
public:
    If(Expression* condition_);
    ~If();
    int walkTree();
};

#endif //IF_H
