#include "ReturnInstructionTranslator.h"
#include "cfg/ir/MovInstruction.h"
#include <iostream>

ReturnInstructionTranslator::ReturnInstructionTranslator(ReturnInstruction* returnInstruction, CFG* cfg) : Translator(returnInstruction, cfg)
{
    // Nothing else to do
}

ReturnInstructionTranslator::~ReturnInstructionTranslator()
{
    // Nothing else to do
}

SubGraph * ReturnInstructionTranslator::translate()
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
    std::vector<BasicBlock*> outputs;

    // Then create a variable to memorize the previous block
    std::vector<BasicBlock*> previousBlocks(1, retBlock);

    if(Translator * t = getFactory().getTranslator(retInstr->getValue(), cfg))
    {
        SubGraph* sb = t->translate();
        BasicBlock* bb = sb->getInput();

        for(BasicBlock* output: previousBlocks)
        {
            // NOTE: if we're at the first child, this should never be executed
            output->setExitTrue(bb);
        }
        previousBlocks = sb->getOutputs();
        delete sb;
        delete t;
    }

    outputs = previousBlocks;

    //TODO: ABI (where should we store Expr's intermediates results and ret value) + MovInstr with 2 registers + No value for register ??????
    retBlock->addInstruction(new MovInstruction(new Register(0/*???*/, "R0"), new Register(0, "R1")));

    // Return a subgraph describing what we just created
    return new SubGraph(retBlock, outputs);
}