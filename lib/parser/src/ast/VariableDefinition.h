#ifndef VARIABLE_DEFINITION_H
#define VARIABLE_DEFINITION_H

#include <string>

#include "AstNode.h"
#include "expression/Expression.h"

class VariableDefinition : public AstNode
{
public:
    VariableDefinition(std::string name_, Expression* rexpression_);
    virtual ~VariableDefinition();

    virtual int walkTree();

protected:
    std::string name;
    Expression* rexpression;
};

#endif