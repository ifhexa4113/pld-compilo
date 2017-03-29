#ifndef BREAK_INSTRUCTION_H
#define BREAK_INSTRUCTION_H

#include "Instruction.h"

class BreakInstruction : public Instruction
{
public:
    BreakInstruction();
    int walkTree();
};

#endif