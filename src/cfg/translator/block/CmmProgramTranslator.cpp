#include "CmmProgramTranslator.h"
#include <iostream>
#include <vector>

CmmProgramTranslator::CmmProgramTranslator(CmmProgram* program, CFG* cfg) : Translator(program, cfg)
{
    // Nothing else to do
}

CmmProgramTranslator::~CmmProgramTranslator()
{
    // Nothing else to do
}

SubGraph * CmmProgramTranslator::translate(Table* table)
{
    // NOTE: We don't need the table at this level.
    //       Therefore, we won't pass any parameter to each child translator:
    //       The child will have to create it by itself.
    table = nullptr;    // Avoid warning

    // First cast it in something we can manipulate as we want
    CmmProgram* cmmProgram = dynamic_cast<CmmProgram*>(node);
    if(cmmProgram == nullptr)
    {
        std::cerr << "CmmProgramTranslator::translate() : ERROR - associated node is not a CmmProgram" << std::endl;
        return nullptr;
    }

    // Then create a variable to memorize the previous block
    std::vector<BasicBlock*> previousBlocks;
    // And the one to return the pseudo-subgraph at the end
    BasicBlock* firstBlock = nullptr;

    // Then appends each child to the cfg
    // (children are only functions definitions here, so it's linear)
    for(AstNode* child: cmmProgram->getChildren())
    {
        if(Translator * t = getFactory().getTranslator(child, cfg))
        {
            SubGraph* sb = t->translate(table);
            BasicBlock* bb = sb->getInput();

            if(!firstBlock)
            {
                // This is the first block, the one that will be returned as the input of the CFG
                firstBlock = bb;
            }

            for(BasicBlock* output: previousBlocks)
            {
                // NOTE: if we're at the first child, this should never be executed
                output->setExitTrue(bb);
            }
            previousBlocks = sb->getOutputs();
            delete sb;
            delete t;
        }
    }

    // Just return a subgraph containing only the outputs of the last subgraph
    return new SubGraph(firstBlock, previousBlocks);
}