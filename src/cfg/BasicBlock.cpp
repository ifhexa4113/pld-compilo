#include "BasicBlock.h"

BasicBlock::BasicBlock(std::string label_, BasicBlock* exitTrue_, BasicBlock* exitFalse_) :
    label(label_),
    instructions(),
    exitTrue(exitTrue_),
    exitFalse(exitFalse_)
{
    // Nothing else to do
}

BasicBlock::~BasicBlock()
{
    for(IRInstruction* instruction: instructions)
    {
        delete instruction;
    }
    if(exitTrue != nullptr)
    {
        delete exitTrue;
    }
    if(exitFalse != nullptr)
    {
        delete exitFalse;
    }
}

std::string BasicBlock::getLabel() const
{
    return label;
}

std::vector<IRInstruction *> BasicBlock::getInstructions() const
{
    return instructions;
}

void BasicBlock::addInstruction(IRInstruction * instruction)
{
    instructions.push_back(instruction);
}

BasicBlock* BasicBlock::getExitTrue()
{
    return exitTrue;
}

BasicBlock* BasicBlock::getExitFalse()
{
    return exitFalse;
}

void BasicBlock::setExitTrue(BasicBlock *exitTrue_)
{
    if(exitTrue != nullptr)
    {
        delete exitTrue;
    }
    exitTrue = exitTrue_;
}

void BasicBlock::setExitFalse(BasicBlock *exitFalse_)
{
    if(exitFalse != nullptr)
    {
        delete exitFalse;
    }
    exitFalse = exitFalse_;
}