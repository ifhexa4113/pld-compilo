#include "WhileTranslator.h"
#include <iostream>
#include <vector>

#include "cfg/ir/comp/CmpInstruction.h"

WhileTranslator::WhileTranslator(While *wh, CFG *cfg) : Translator(wh, cfg)
{
    // Nothing else to do
}

WhileTranslator::~WhileTranslator()
{
    // Nothing else to do
}

SubGraph * WhileTranslator::translate(Table* table)
{
    // First cast it in something we can manipulate as we want
    While* wh = dynamic_cast<While*>(node);
    if(wh == nullptr)
    {
        std::cerr << "WhileTranslator::translate() : ERROR - associated node is not a While" << std::endl;
        return nullptr;
    }

    // Then translate the condition (note: it must be something, it can't be empty)
    Translator * ct = getFactory().getTranslator(wh->getCondition(), cfg);
    SubGraph* csb = ct->translate(table);
    // At this point, the condition's output must only have one BB
    // If the last register contains 1 or more, the condition is true
    BasicBlock* conditionBlockInput = csb->getInput();
    conditionBlockInput->giveLabel();
    
    // Add compare and right jump to the condition
    BasicBlock* conditionBlockOutput = csb->getOutputs().back();
    conditionBlockOutput->addInstruction(new CmpInstruction(
        table->getLastDestination(conditionBlockOutput),
        table->getOrCreateNumberOperand(0)));
    conditionBlockOutput->setExitJumpType(BasicBlock::JumpType::Z);

    delete csb;
    delete ct;

    // Then create the block where to body will lie
    BasicBlock* body = new BasicBlock();
    // And be sure to link the condition's exitFalse to it
    conditionBlockOutput->setExitFalse(body);

    // Then create a variable to memorize the previous block
    // std::vector<BasicBlock*> previousBlocks;

    // Then gather the subgraph from children
    for(AstNode* child: wh->getChildren())
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

    body->setExitTrue(conditionBlockInput);

    // Eventually return a subgraph describing what we just created
    return new SubGraph(conditionBlockInput, std::vector<BasicBlock*>(1, conditionBlockInput));
}