#include "ArrayListDefinition.h"

ArrayListDefinition::ArrayListDefinition(std::string name_, std::vector<Expression*> listExpression_) :
    Definition(name_),
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