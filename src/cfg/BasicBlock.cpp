#include "BasicBlock.h"
#include <sstream>
#include <iostream>

int BasicBlock::labelCounter = 0;

// ---------------------------------------- Constructors / Destructors

BasicBlock::BasicBlock(std::string label_, BasicBlock* exitTrue_, BasicBlock* exitFalse_, BasicBlock::JumpType exitJumpType_) :
    label(([&label_]() {
        if(label_ == "%%unnamed%%") {
            std::stringstream ss;
            ss << "_bb" << BasicBlock::labelCounter++;
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
        // TODO BUG with the delete
        //delete exitTrue;
    }
    exitTrue = exitTrue_;
}

void BasicBlock::setExitFalse(BasicBlock *exitFalse_)
{
    if(exitFalse != nullptr)
    {
        // TODO BUG with the delete
        //delete exitFalse;
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

    // parcours les sorties fausses en profondeur
    if(exitFalse != nullptr)
    {
        if(exitFalse->getLabel() != "")
        {
            printJump(ost, exitFalse->getExitJumpType());
            ost << exitFalse->getLabel() << std::endl;
        }
        if(exitTrue != nullptr)
        {
            ost << "JMP\t " << exitTrue->getLabel() << std::endl;
        }

        if(!exitFalse->isColored())
        {
            exitFalse->print(ost);
        }
    }

    // si on n'est pas à la fin du programme
    if(exitTrue != nullptr)
    {
        // le bloc n'a pas d'exit false donc on jump
        if(exitFalse == nullptr)
        {
            ost << "JMP\t " << exitTrue->getLabel() << std::endl;
        }

        if(!exitTrue->isColored())
        {
            exitTrue->print(ost);
        }
    }
}

void BasicBlock::printJump(std::ostream &ost, JumpType jump)
{
    switch(jump)
    {
    case JumpType::Z:
        ost << "JMPZ\t ";
        break;
    case JumpType::N:
        ost << "JMPN\t ";
        break;
    case JumpType::NZ:
        ost << "JMPNZ\t ";
        break;
    }
}

void BasicBlock::giveLabel()
{
    if(label == "")
    {
        std::stringstream ss;
        ss << "_bb" << BasicBlock::labelCounter++;
        label = ss.str();
    }
}

Table *BasicBlock::getTable() const {
    return table;
}
