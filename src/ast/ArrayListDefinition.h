#ifndef ARRAY_LIST_DEFINITION_H
#define ARRAY_LIST_DEFINITION_H

#include <vector>

#include "AstNode.h"
#include "expression/Expression.h"

class ArrayListDefinition : public AstNode
{
public:
    ArrayListDefinition(std::vector<Expression*> list);
    ~ArrayListDefinition();

    virtual int walkTree();

protected:
    std::vector<Expression*> listExpression;
};

#endif