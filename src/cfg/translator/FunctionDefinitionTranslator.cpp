#include "FunctionDefinitionTranslator.h"
#include <iostream>

FunctionDefinitionTranslator::FunctionDefinitionTranslator(FunctionDefinition* functionDef, CFG* cfg) : Translator(functionDef, cfg)
{
    // Nothing else to do
}

FunctionDefinitionTranslator::~FunctionDefinitionTranslator()
{
    // Nothing else to do
}

SubGraph * FunctionDefinitionTranslator::translate()
{
    // TODO: what about the return ???
    // TODO: handle merging blocks here or after completing the whole cfg ?

    // First cast it in something we can manipulate as we want
    FunctionDefinition* fDef = dynamic_cast<FunctionDefinition*>(node);
    if(fDef == nullptr)
    {
        std::cerr << "FunctionDefinitionTranslator::translate() : ERROR - associated node is not a FunctionDefinition" << std::endl;
        return nullptr;
    }

    // Then create bases for the subgraph that we'll return
    BasicBlock* functionBlock = new BasicBlock(fDef->getName());    // The function block; input of the subgraph
    std::vector<BasicBlock*> outputs;                               // The list of subgraph's outputs

    // Then create a variable to memorize the previous block
    std::vector<BasicBlock*> previousBlocks(1, functionBlock);

    // TODO: I think that in all cases, the first block could be merged in the functionBlock
    // TODO     (replace label of the first block by the one of the functionBlock)

    // For each child, link subgraphs
    for(AstNode* child: fDef->getChildren())
    {
        if(Translator * t = getFactory().getTranslator(child, cfg))
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
    }

    outputs = previousBlocks;
    // TODO: if there was a return; instruction somewhere else in the rest, we must add it to the outputs

    // Return a subgraph describing what we just created
    return new SubGraph(functionBlock, outputs);
}