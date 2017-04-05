#include "BasicBlock.h"
#include <sstream>
#include <iostream>

int BasicBlock::labelCounter = 0;

// ---------------------------------------- Constructors / Destructors

BasicBlock::BasicBlock(std::string label_, BasicBlock* exitTrue_, BasicBlock* exitFalse_, BasicBlock::JumpType exitJumpType_) :
    label(([&label_]() {
        if(label_ == "%%unnamed%%") {
            std::stringstream ss;
            ss << "%bb" << BasicBlock::labelCounter++;
            return ss.str();
        }
        return label_;
    })()),
    instructions(),
    exitTrue(exitTrue_),
    exitFalse(exitFalse_),
    exitJumpType(exitJumpType_),
    table(nullptr),
    colored(false),
    prologable(false)
{
    // Nothing else to do
}

BasicBlock::~BasicBlock()
{
    // Delete each instruction
    for(IRInstruction* instruction: instructions)
    {
        delete instruction;
    }
    // Delete table if needed
    if(isPrologable() && table)
    {
        // Only the BB which will generate a prolog are able to destroy a Table
        delete table;
    }

    // NOTE: since basic blocks are organized as a graph,
    //       it's the CFG that will destroy them.
}

// ---------------------------------------- Getters

std::string BasicBlock::getLabel() const
{
    return label;
}

std::vector<IRInstruction *>& BasicBlock::getInstructions()
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

Table* BasicBlock::getTable()
{
    return table;
}

bool BasicBlock::isColored()
{
    return colored;
}

bool BasicBlock::isPrologable()
{
    return prologable;
}

// ---------------------------------------- Setters

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

void BasicBlock::setTable(Table * t)
{
    table = t;
}

void BasicBlock::setColored(bool colored_){
    colored = colored_;
}

void BasicBlock::setPrologable(bool prologable_){
    prologable = prologable_;
}

// ---------------------------------------- Others

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

    // L'exit TRUE et False du otherBlock deviennent ceux du Block courant
    setExitTrue(otherBlock->getExitTrue());
    otherBlock->setExitTrue(nullptr);
    setExitFalse(otherBlock->getExitFalse());
    otherBlock->setExitFalse(nullptr);
}

void BasicBlock::print(std::ostream &ost)
{
    // TODO FIX print
    if(isColored())
    {
        return;
    }
    setColored();
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
        if(!(exitTrue->isColored()))
        {
            exitTrue->print(ost);
        } else {
            ost << "JMP\t " << exitTrue->getLabel() << std::endl;
        }
    }
    if(exitFalse)
    {
        ost << "JMPNZ\t" << exitFalse->getLabel() << std::endl;
        if(!(exitFalse->isColored()))
        {
            exitFalse->print(ost);
        }
    }
}

void BasicBlock::giveLabel()
{
    if(label == "")
    {
        std::stringstream ss;
        ss << "%bb" << BasicBlock::labelCounter++;
        label = ss.str();
    }
}
