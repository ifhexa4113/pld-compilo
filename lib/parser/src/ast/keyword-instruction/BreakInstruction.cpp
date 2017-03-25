#include <iostream>
#include "BreakInstruction.h"

BreakInstruction::BreakInstruction() :
    AstNode()
{
    // Nothing else to do
}

int BreakInstruction::walkTree()
{
    std::cout << "Break instruction" << std::endl;
    return 0;
}
