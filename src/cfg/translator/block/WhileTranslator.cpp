#include "WhileTranslator.h"
#include <iostream>
#include <vector>

WhileTranslator::WhileTranslator(While *wh, CFG *cfg) : Translator(wh, cfg)
{
    // Nothing else to do
}

WhileTranslator::~WhileTranslator()
{
    // Nothing else to do
}

SubGraph * WhileTranslator::translate()
{
    // First cast it in something we can manipulate as we want
    While* wh = dynamic_cast<While*>(node);
    if(wh == nullptr)
    {
        std::cerr << "WhileTranslator::translate() : ERROR - associated node is not a While" << std::endl;
        return nullptr;
    }

    // Then translate the condition
    Translator * ct = getFactory().getTranslator(wh->getCondition(), cfg);
    SubGraph* csb = ct->translate();
    // At this point, we're sure that the input and the output are the same
    BasicBlock* conditionBlock = csb->getInput();
    delete csb;
    delete ct;

    // Then create a variable to memorize the previous block
    std::vector<BasicBlock*> previousBlocks;

    // Then gather the subgraph from children
    for(AstNode* child: wh->getChildren())
    {
        if(Translator * t = getFactory().getTranslator(child, cfg))
        {
            SubGraph* sb = t->translate();
            BasicBlock* bb = sb->getInput();

            if(previousBlocks.size() == 0)
            {
                // This is the first child
                // We must link the condition's exitFalse to it
                // TODO: how the hell do we chose which jump instruction to use ?
                // TODO: does this depend of the last instruction of the block ?
                conditionBlock->setExitFalse(bb);
            }

            for(BasicBlock* output: previousBlocks)
            {
                // NOTE: if we're at the first child, this should never be executed
                output->setExitTrue(bb);
                // TODO: handle a break instruction here ?
            }
            previousBlocks = sb->getOutputs();
            delete sb;
            delete t;
        }
    }

    // Then link the last outputs to the condition
    // TODO: what if there was a break somewhere in the while ?
    for(BasicBlock* output: previousBlocks)
    {
        output->setExitTrue(conditionBlock);
    }

    // Eventually return a subgraph describing what we just created
    return new SubGraph(conditionBlock, std::vector<BasicBlock*>(1, conditionBlock));
}