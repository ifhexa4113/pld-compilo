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
        //delete exitTrue;
    }
    exitTrue = exitTrue_;
}

void BasicBlock::setExitFalse(BasicBlock *exitFalse_)
{
    if(exitFalse != nullptr)
    {
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

// void BasicBlock::print(std::ostream &ost)
// {
//     if(isColored())
//     {
//         return;
//     }
//     setColored();
//     if(label != "")
//     {
//         ost << label << ":" << std::endl;
//     }
//     for(IRInstruction* instruction: instructions)
//     {
//         instruction->print(ost);
//     }
//     if(exitTrue)
//     {
//         if(!(exitTrue->isColored()))
//         {
//             exitTrue->print(ost);
//         } else {
//             ost << "JMP\t " << exitTrue->getLabel() << std::endl;
//         }
//     }
//     if(exitFalse)
//     {
//         ost << "JMPNZ\t" << exitFalse->getLabel() << std::endl;
//         if(!(exitFalse->isColored()))
//         {
//             exitFalse->print(ost);
//         }
//     }
// }

void BasicBlock::giveLabel()
{
    if(label == "")
    {
        std::stringstream ss;
        ss << "_bb" << BasicBlock::labelCounter++;
        label = ss.str();
    }
}

void BasicBlock::print(std::ostream &ost)
{
    if(label != "")
    {
        ost << label << ":" << std::endl;
    }
    for(IRInstruction* instruction: instructions)
    {
        instruction->print(ost);
    }

    if(exitFalse != nullptr)
    {
        // On commence un graphe
        std::cout << "JMPZ\t" << exitTrue->getLabel() <<  std::endl;

        setColored();

        // sauvegarde du bloc de sortie du graphe non linéaire
        // TODO SEGFAULT replace
        //BasicBlock* endBlock = nullptr;
        BasicBlock* endBlock = exitTrue;

        // parcours du graphe non linéaire
        walkCfgPrint(std::cout, exitFalse, &endBlock);

        // le bloc de fin de graphe (l'endroit ou le bloc converge)
        // on revient à une partie linéaire
        endBlock->print(ost);
    }
    else
    {
        if(exitTrue != nullptr)
        {
            ost << "JMP\t " << exitTrue->getLabel() << std::endl;
            exitTrue->print(ost);
        }
    }

}

void BasicBlock::walkCfgPrint(std::ostream &ost, BasicBlock* block, BasicBlock** endBlock)
{
    if(block->getLabel() != "")
    {
        ost << block->getLabel()  << ":" << std::endl;
    }
    for(IRInstruction* instruction: block->getInstructions())
    {
        instruction->print(ost);
    }

    if(block->getExitFalse())
    {
        // On continue sur la branche false tant qu'elle existe
        ost << "JMPZ\t " << block->getExitTrue()->getLabel() << std::endl;
        walkCfgPrint(ost, block->getExitFalse(), endBlock);
    }
    else
    {
        // On est arrivé au bout d'une branche false, on check si le block true 
        // est le bloc de fin (ne l'est pas dans une boucle cf while)
        // TODO SEGFAULT
        // BasicBlock* endBlockParent = block->getExitTrue();
        // if(endBlockParent != nullptr)
        // {
        //     if(endBlockParent->getExitFalse() == nullptr)
        //     {
        //         *endBlock = block->getExitTrue();
        //         return;
        //     }
        // }
    }

    // On recommence à cherche les blocks false en profondeur à partir
    // du block true du dessus.
    BasicBlock* myExitTrue = block->getExitTrue();
    if(*endBlock != myExitTrue && myExitTrue != nullptr)
    {
        ost << "JMP\t " << block->getExitTrue()->getLabel() << std::endl;
        if(!myExitTrue->isColored())
        {
            block->getExitTrue()->setColored();
            walkCfgPrint(ost, block->getExitTrue(), endBlock);
        }
    }
}