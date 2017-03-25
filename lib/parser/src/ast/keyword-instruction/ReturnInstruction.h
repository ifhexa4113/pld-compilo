#ifndef RETURN_H
#define RETURN_H

#include "ast/AstNode.h"
#include "ast/expression/Expression.h"

class ReturnInstruction : public AstNode
{
public:
    ReturnInstruction(Expression* value_);
    ~ReturnInstruction();
    int walkTree();
    Expression* getValue() const;

protected:
    Expression* value;
};

#endif