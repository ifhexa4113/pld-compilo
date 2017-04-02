#include "ForTranslator.h"
#include "ast/expression/Expression.h"
#include "ast/expression/NullExpression.h"
#include <iostream>
#include <vector>

ForTranslator::ForTranslator(For *f, CFG *cfg) : Translator(f, cfg)
{
    // Nothing else to do
}

ForTranslator::~ForTranslator()
{
    // Nothing else to do
}

SubGraph * ForTranslator::translate()
{
    // First cast it in something we can manipulate as we want
    For* f = dynamic_cast<For*>(node);
    if(f == nullptr)
    {
        std::cerr << "ForTranslator::translate() : ERROR - associated node is not a For" << std::endl;
        return nullptr;
    }

    // Then create the basic blocks of the for
    BasicBlock* forBlock = new BasicBlock("");
    BasicBlock* forBodyBlock = new BasicBlock();
    BasicBlock* conditionBlock;
    BasicBlock* initBlock;
    BasicBlock* incrementBlock;

    // Then translate the condition if needed
    Expression* e = f->getCondition();
    if(dynamic_cast<NullExpression*>(e) == nullptr)
    {
        Translator * ct = getFactory().getTranslator(e, cfg);
        SubGraph* csb = ct->translate();
        // At this point, we're sure that the input and the output are the same
        conditionBlock = csb->getInput();
        delete csb;
        delete ct;
    } else {
        conditionBlock = new BasicBlock();
    }
    conditionBlock->setExitFalse(forBodyBlock);

    // Then translate the init if needed
    AstNode* an = f->getInitialization();
    if(dynamic_cast<NullExpression*>(an) == nullptr)
    {
        Translator * it = getFactory().getTranslator(an, cfg);
        SubGraph* isb = it->translate();
        // At this point, we're sure that the input and the output are the same
        // TODO: are we really ?
        initBlock = isb->getInput();
        delete isb;
        delete it;
        forBlock->setExitTrue(initBlock);
        initBlock->setExitTrue(conditionBlock);
        // TODO: merge the things above
    } else {
        forBlock->setExitTrue(conditionBlock);
    }

    // Then translate the increment if needed
    e = f->getIncrement();
    if(dynamic_cast<NullExpression*>(e) == nullptr)
    {
        Translator * it = getFactory().getTranslator(e, cfg);
        SubGraph* isb = it->translate();
        // At this point, we're sure that the input and the output are the same
        incrementBlock = isb->getInput();
        delete isb;
        delete it;
    }

    // Then create a variable to memorize the previous block
    std::vector<BasicBlock*> previousBlocks;

    // Then gather the subgraph from children
    for(AstNode* child: f->getChildren())
    {
        if(Translator * t = getFactory().getTranslator(child, cfg))
        {
            SubGraph* sb = t->translate();
            BasicBlock* bb = sb->getInput();

            if(previousBlocks.size() == 0)
            {
                // This is the first child
                // We must link the initialization's exitTrue to it
                forBodyBlock->setExitTrue(bb);
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

    // Then link the last outputs to the increment
    for(BasicBlock* output: previousBlocks)
    {
        output->setExitTrue(incrementBlock);
    }

    // Then link the increment to the condition
    if(incrementBlock != nullptr)
    {
        incrementBlock->setExitTrue(conditionBlock);
    }

    // Eventually return a subgraph describing what we just created
    return new SubGraph(forBlock, std::vector<BasicBlock*>(1, conditionBlock));

}