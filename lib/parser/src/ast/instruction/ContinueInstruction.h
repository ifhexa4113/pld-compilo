#ifndef CONTINUE_INSTRUCTION_H
#define CONTINUE_INSTRUCTION_H

#include "Instruction.h"

class ContinueInstruction : public Instruction
{
public:
    ContinueInstruction();
    int walkTree();
    void fillAstTrace(std::string& astTrace);
    bool checkReturnType(Type, SymbolTableStack&){return false;};
};

#endif