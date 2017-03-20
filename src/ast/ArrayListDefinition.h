#ifndef ARRAY_LIST_DEFINITION_H
#define ARRAY_LIST_DEFINITION_H

#include <vector>

#include "AstNode.h"

class ArrayListDefinition : public AstNode
{
public:
    ArrayListDefinition(std::vector<Expression*> list);
    ~ArrayList();

    virtual int walkTree();

protected:
    std::vector<Expression*> listExpression;
};

#endif