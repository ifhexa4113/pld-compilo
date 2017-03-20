#ifndef VARIABLE_DEFINITION_H
#define VARIABLE_DEFINITION_H

#include "AstNode.h"

class VariableDefinition : public AstNode
{
public:
    VariableDefinition(Expression* expression);
    virtual ~VariableDefinition();

    virtual int walkTree();

protected:
    Expression* expression;
};

#endif