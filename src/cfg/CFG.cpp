#include "CFG.h"

CFG::CFG(Ast *ast_) : ast(ast_), blocks()
{
    // Nothing else to do
}

CFG::~CFG()
{
    for(BasicBlock* bb: blocks)
    {
        delete bb;
    }
}

void CFG::addBasicBlock(BasicBlock *block)
{
    blocks.push_back(block);
}