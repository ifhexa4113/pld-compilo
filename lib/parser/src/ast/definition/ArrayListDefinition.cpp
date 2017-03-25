#include "ArrayListDefinition.h"

ArrayListDefinition::ArrayListDefinition(LValueDeclaration* declaration_, std::vector<Expression*> listExpression_) :
    Definition(declaration_),
    listExpression(listExpression_)
{
    // Nothing else to do
}

ArrayListDefinition::~ArrayListDefinition()
{
    for(auto expression : listExpression)
    {
        delete expression;
    }
}

int ArrayListDefinition::walkTree()
{
    return 0;
}

std::vector<Expression *> ArrayListDefinition::getListExpression()
{
    return listExpression;
}