#include "VariableDefinition.h"

VariableDefinition::VariableDefinition(Expression* expression) : 
    this->expression(expression)
{
    #ifdef DEBUG
        id = AstNode.IdMax++;
        std::cout << "Creating VariableDefinition node, id: " << id << std::endl;
    #endif
}

VariableDefinition::~VariableDefinition()
{
    delete expression;
}

int VariableDefinition::walkTree()
{
    
}