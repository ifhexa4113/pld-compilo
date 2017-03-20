#ifdef DEBUG
    #include <iostream>
#endif

#include "VariableDefinition.h"

VariableDefinition::VariableDefinition(Expression* expression) : 
    AstNode(),
    this->expression(expression)
{
    
}

VariableDefinition::~VariableDefinition()
{
    delete expression;
}

int VariableDefinition::walkTree()
{

}