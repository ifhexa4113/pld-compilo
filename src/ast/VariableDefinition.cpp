#include "VariableDefinition.h"

VariableDefinition::VariableDefinition(std::string name, Expression* rexpression) : 
    AstNode(),
    this->name(name),
    this->rexpression(rexpression)
{
    
}

VariableDefinition::~VariableDefinition()
{
    delete expression;
}

int VariableDefinition::walkTree()
{

}