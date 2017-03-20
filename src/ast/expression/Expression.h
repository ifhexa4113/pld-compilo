#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "../AstNode.h"

class Expression : public AstNode
{
public:
    Expression() {};
    virtual ~Expression() {};

    virtual int walkTree() = 0;
};

#endif