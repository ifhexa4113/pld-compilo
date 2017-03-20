#ifndef VARIABLE_DEFINITION_H
#define VARIABLE_DEFINITION_H

#include <string>

#include "AstNode.h"

class VariableDefinition : public AstNode
{
public:
    VariableDefinition(std::string name, Expression* rexpression);
    virtual ~VariableDefinition();

    virtual int walkTree();

protected:
    std::string name;
    Expression* rexpression;
};

#endif