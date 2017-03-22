#include <iostream>

#include "BreakInstruction.h"

BreakInstruction::BreakInstruction() :
    AstNode()
{

}

int BreakInstruction::walkTree()
{
    std::cout << "Break instruction" << std::endl;
}
