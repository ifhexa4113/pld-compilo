#include "BlockTranslator.h"
#include <iostream>
#include <vector>

#include "cfg/ir/comp/CmpInstruction.h"

BlockTranslator::BlockTranslator(Block *block, CFG *cfg) : Translator(block, cfg)
{
    // Nothing else to do
}

BlockTranslator::~BlockTranslator()
{
    // Nothing else to do
}

SubGraph * BlockTranslator::translate(Table* table)
{
    // First cast it in something we can manipulate as we want
    Block* block = dynamic_cast<Block*>(node);
    if(block == nullptr)
    {
        std::cerr << "BlockTranslator::translate() : ERROR - associated node is not a Block" << std::endl;
        return nullptr;
    }

    std::vector<AstNode*> children = block->getChildren();
    if(children.empty())
    {
        BasicBlock* emptyBlock = new BasicBlock("");
        return new SubGraph(emptyBlock, std::vector<BasicBlock*>(1, emptyBlock));
    }

    BasicBlock* input;
    std::vector<BasicBlock*> previousOutputs;
    if(Translator * t = getFactory().getTranslator(children.front(), cfg))
    {
        SubGraph* sb = t->translate(table);
        input = sb->getInput();
        previousOutputs = sb->getOutputs();
        delete sb;
        delete t;
    }

    for(int i = 1; i < children.size(); i++)
    {
        if(Translator * t = getFactory().getTranslator(children[i], cfg))
        {
            SubGraph* sb = t->translate(table);
            BasicBlock* bb = sb->getInput();
            if(bb->getLabel() == "")
            {
                // TODO merge instead of giving a label ?
                bb->giveLabel();
            }
            for(BasicBlock* currentOutput : previousOutputs)
            {
                currentOutput->setExitTrue(bb);
            }

            previousOutputs = sb->getOutputs();
            delete sb;
            delete t;
        }
    }

    // Eventually return a subgraph describing what we just created
    return new SubGraph(input, previousOutputs);
}