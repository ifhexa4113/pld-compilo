#include "ReturnInstructionTranslator.h"
#include "cfg/ir/basic/MovInstruction.h"
#include <iostream>

ReturnInstructionTranslator::ReturnInstructionTranslator(ReturnInstruction* returnInstruction, CFG* cfg) : Translator(returnInstruction, cfg)
{
    // Nothing else to do
}

ReturnInstructionTranslator::~ReturnInstructionTranslator()
{
    // Nothing else to do
}

SubGraph * ReturnInstructionTranslator::translate(Table* table)
{
    // First cast it in something we can manipulate as we want
    ReturnInstruction* retInstr = dynamic_cast<ReturnInstruction*>(node);
    if(retInstr == nullptr)
    {
        std::cerr << "ReturnInstructionTranslator::translate() : ERROR - associated node is not a ReturnInstruction" << std::endl;
        return nullptr;
    }

    // Then create bases for the subgraph that we'll return
    BasicBlock* retBlock = new BasicBlock();
    retBlock->setTable(table);

    Translator* t = getFactory().getTranslator(retInstr->getValue(), cfg);
    SubGraph* sb = t->translate(table);

    BasicBlock* expr = sb->getInput();
    expr->setExitTrue(retBlock);

    // TODO: ABI (where should we store Expr's intermediates results and ret value) + MovInstr with 2 registers + No value for register ??????
    retBlock->addInstruction(new MovInstruction(
        table->getOrCreateRegister(),
        table->getLastDestination(expr)
    ));

    delete sb;
    delete t;

    // Return a subgraph describing what we just created
    // TODO: the outputs should not be empty ?
    return new SubGraph(expr, std::vector<BasicBlock*>());
}