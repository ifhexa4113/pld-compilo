#ifdef DEBUG
    #include <iostream>
#endif

#include "ArrayListDefinition.h"

ArrayListDefinition::ArrayListDefinition(std::vector<Expression*> list) :
    AstNode(),
    listExpression(list)
{

}

ArrayListDefinition::~ArrayListDefinition()
{
    for(auto expression : listExpression)
        delete expression;
}

int ArrayListDefinition::walkTree()
{
    
}