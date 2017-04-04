#ifndef ARRAY_LIST_DEFINITION_H
#define ARRAY_LIST_DEFINITION_H

#include <string>
#include <vector>
#include "Definition.h"
#include "ast/expression/Expression.h"
#include "ast/declaration/LValueDeclaration.h"

class ArrayListDefinition : public Definition
{
public:
    ArrayListDefinition(LValueDeclaration* declaration_, std::vector<Expression*> listExpression_);
    ~ArrayListDefinition();
    int walkTree();
    std::vector<Expression*> getListExpression();

    void fillSymbolTable(SymbolTableStack& stack);
    void fillAstTrace(std::string& astTrace);

protected:
    std::vector<Expression*> listExpression;
};

#endif