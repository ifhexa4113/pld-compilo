#include "VariableDefinition.h"

VariableDefinition::VariableDefinition(std::string name_, Expression* rexpression_) : 
    AstNode(),
    name(name_),
    rexpression(rexpression_)
{
    
}

VariableDefinition::~VariableDefinition()
{
    delete rexpression;
}

int VariableDefinition::walkTree()
{

}