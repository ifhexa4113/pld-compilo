#include <iostream>
#include "ContinueInstruction.h"

ContinueInstruction::ContinueInstruction() :
        Instruction()
{
    // Nothing else to do
}

int ContinueInstruction::walkTree()
{
    std::cout << "Continue instruction" << std::endl;
    return 0;
}

void ContinueInstruction::fillAstTrace(std::string& astTrace)
{
    astTrace += "CONTINUE\n";
}