#include <iostream>
#include "BreakInstruction.h"

BreakInstruction::BreakInstruction() :
    Instruction()
{
    // Nothing else to do
}

int BreakInstruction::walkTree()
{
    std::cout << "Break instruction" << std::endl;
    return 0;
}

void BreakInstruction::fillAstTrace(std::string& astTrace)
{
    astTrace += "BREAK\n";
}