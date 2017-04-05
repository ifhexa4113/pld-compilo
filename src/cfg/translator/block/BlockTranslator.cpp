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

    // Then create the block where to body will lie
    BasicBlock* body = new BasicBlock();

    // Then gather the subgraph from children
    for(AstNode* child: block->getChildren())
    {
        if(Translator * t = getFactory().getTranslator(child, cfg))
        {
            SubGraph* sb = t->translate(table);
            BasicBlock* bb = sb->getInput();

            // Just merge it for the moment
            body->merge(bb);

            // TODO: find something better than a merge

            delete sb;
            delete t;
        }
    }

    // Eventually return a subgraph describing what we just created
    return new SubGraph(body, std::vector<BasicBlock*>(1, body));
}