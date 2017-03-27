#include <iostream>
#include "CmmProgram.h"

CmmProgram::CmmProgram() : Block()
{
    // Nothing else to do
}

CmmProgram::CmmProgram(std::vector<AstNode*> children_) :
    Block(children_)
{
    // Nothing else to do
}

CmmProgram::~CmmProgram()
{
    // Nothing else to do
}

int CmmProgram::walkTree()
{
    std::cout << "Entering C--Program, iterating through children" << std::endl;
    Block::walkTree();
    return 0;
}

void CmmProgram::addFunction(FunctionDefinition* function)
{
    // TODO: check symbol table
    // TODO: update symbol table
    children.push_back(function);
}
