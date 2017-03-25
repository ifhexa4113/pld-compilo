#ifndef BREAK_INSTRUCTION_H
#define BREAK_INSTRUCTION_H

#include "../AstNode.h"

class BreakInstruction : public AstNode
{
public:
    BreakInstruction();
    int walkTree();
};

#endif