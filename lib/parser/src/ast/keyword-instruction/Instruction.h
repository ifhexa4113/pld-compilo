#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "ast/AstNode.h"

class Instruction : public AstNode
{
public:
    Instruction() : AstNode() {};
    virtual ~Instruction() {};
    virtual int walkTree() = 0;
};

#endif