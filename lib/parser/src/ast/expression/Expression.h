#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "ast/AstNode.h"

class Expression : public AstNode
{
public:
    Expression() {};
    virtual ~Expression() {};
    virtual int walkTree() = 0;
};

#endif