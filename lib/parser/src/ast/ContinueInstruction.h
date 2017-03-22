#ifndef CONTINUE_INSTRUCTION_H
#define CONTINUE_INSTRUCTION_H

#include "AstNode.h"

class ContinueInstruction : public AstNode
{
public:
    ContinueInstruction();

    virtual int walkTree();
};

#endif