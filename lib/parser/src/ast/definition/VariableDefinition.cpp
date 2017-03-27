#include "VariableDefinition.h"
#include "ast/expression/NullExpression.h"

VariableDefinition::VariableDefinition(LValueDeclaration* declaration_, Expression* rExpression_) :
    Definition(declaration_),
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

void VariableDefinition::fillSymbolTable(SymbolTableStack& stack)
{
    Definition::fillSymbolTable(stack);
    rExpression->fillSymbolTable(stack);
}