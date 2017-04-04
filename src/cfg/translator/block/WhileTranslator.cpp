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
    std::vector<BasicBlock*> conditionBlockOutputs = csb->getOutputs();
    // TODO: do something to actually compare it ?
    delete csb;
    delete ct;

    // Then create the block where to body will lie
    BasicBlock* body = new BasicBlock();
    // And be sure to link the condition's exitFalse to it
    for(auto output: conditionBlockOutputs)
    {
        std::cout << "Setting outputs false to point to body..." << std::endl;
        // NOTE: only one in theory, but hey...
        output->setExitFalse(body);
    }

    std::cout << "... Done." << std::endl;

    body->setExitTrue(conditionBlockInput);

    // Then create a variable to memorize the previous block
    // std::vector<BasicBlock*> previousBlocks;

    std::cout << "There are " << wh->getChildren().size() << " children." << std::endl;

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

//    std::cout << "Body:" << std::endl;
//    body->print(std::cout);
//    std::cout << "Condition:" << std::endl;
//    conditionBlockInput->print(std::cout);

    // Eventually return a subgraph describing what we just created
    return new SubGraph(conditionBlockInput, conditionBlockOutputs);
}