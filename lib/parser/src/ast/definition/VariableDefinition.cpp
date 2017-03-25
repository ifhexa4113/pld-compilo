#include "VariableDefinition.h"
#include "ast/expression/NullExpression.h"

VariableDefinition::VariableDefinition(std::string name_, Expression* rExpression_) :
    Definition(name_),
    rExpression(rExpression_)
{
    if(rExpression == nullptr)
    {
        rExpression = new NullExpression();
    }
}

VariableDefinition::~VariableDefinition()
{
    delete rExpression;
}

int VariableDefinition::walkTree()
{
    return 0;
}

Expression * VariableDefinition::getRExpression()
{
    return rExpression;
}