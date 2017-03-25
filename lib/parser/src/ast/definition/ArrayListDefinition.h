#ifndef ARRAY_LIST_DEFINITION_H
#define ARRAY_LIST_DEFINITION_H

#include <string>
#include <vector>
#include "Definition.h"
#include "ast/expression/Expression.h"
#include "ast/declaration/ArrayDeclaration.h"

class ArrayListDefinition : public Definition
{
public:
    ArrayListDefinition(ArrayDeclaration* declaration_, std::vector<Expression*> listExpression_);
    ~ArrayListDefinition();
    int walkTree();
    std::vector<Expression*> getListExpression();

protected:
    std::vector<Expression*> listExpression;
};

#endif