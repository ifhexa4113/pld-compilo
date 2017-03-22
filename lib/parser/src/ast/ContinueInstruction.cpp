#include <iostream>

#include "ContinueInstruction.h"

ContinueInstruction::ContinueInstruction() :
    AstNode()
{

}

int ContinueInstruction::walkTree()
{
    std::cout << "Continue instruction" << std::endl;
    return 0;
}
