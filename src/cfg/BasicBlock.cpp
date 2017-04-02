#include "BasicBlock.h"
#include <sstream>

int BasicBlock::labelCounter = 0;

BasicBlock::BasicBlock(std::string label_, BasicBlock* exitTrue_, BasicBlock* exitFalse_, BasicBlock::JumpType exitJumpType_) :
    label(([&label_]() {
        if(label_ == "$$unnamed$$") {
            std::stringstream ss;
            ss << "$bb" << BasicBlock::labelCounter++;
            return ss.str();
        }
        return label_;
    })()),
    instructions(),
    exitTrue(exitTrue_),
    exitFalse(exitFalse_),
    exitJumpType(exitJumpType_)
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

BasicBlock* BasicBlock::getExitTrue()
{
    return exitTrue;
}

BasicBlock* BasicBlock::getExitFalse()
{
    return exitFalse;
}

BasicBlock::JumpType BasicBlock::getExitJumpType() const
{
    return exitJumpType;
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

void BasicBlock::setExitJumpType(BasicBlock::JumpType j)
{
    exitJumpType = j;
}

void BasicBlock::addInstruction(IRInstruction * instruction)
{
    instructions.push_back(instruction);
}

void BasicBlock::merge(BasicBlock * otherBlock)
{
    for(IRInstruction* instruction: otherBlock->getInstructions())
    {
        instructions.push_back(instruction);
    }
}

void BasicBlock::print(std::ostream &ost) const
{
    if(label != "")
    {
        ost << label << ":" << std::endl;
    }
    for(IRInstruction* instruction: instructions)
    {
        instruction->print(ost);
    }
    if(exitTrue)
    {
        exitTrue->print(ost);
    }
    if(exitFalse)
    {
        exitFalse->print(ost);
    }
}