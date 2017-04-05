#include "IfTranslator.h"
#include "ast/expression/Expression.h"
#include "cfg/ir/comp/CmpInstruction.h"
#include <iostream>
#include <vector>

IfTranslator::IfTranslator(If *f, CFG *cfg) : Translator(f, cfg)
{
    // Nothing else to do
}

IfTranslator::~IfTranslator()
{
    // Nothing else to do
}

SubGraph * IfTranslator::translate(Table* table)
{
    // First cast it in something we can manipulate as we want
    If* f = dynamic_cast<If*>(node);
    if(f == nullptr)
    {
        std::cerr << "IfTranslator::translate() : ERROR - associated node is not a If" << std::endl;
        return nullptr;
    }

    // Then translate the condition (note: it must be something, it can't be empty)
    Translator * ct = getFactory().getTranslator(f->getCondition(), cfg);
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

    std::vector<BasicBlock*> outputs;

    // Then create the block where to body will lie
    BasicBlock* ifBody = new BasicBlock();
    // And be sure to link the condition's exitFalse to it
    conditionBlockOutput->setExitFalse(ifBody);

    if(AstNode* child = f->getIfBlock()->getChildren().front())
    {
        if(Translator * t = getFactory().getTranslator(child, cfg))
        {
            SubGraph* sb = t->translate(table);
            BasicBlock* bb = sb->getInput();

            for(BasicBlock* endIfBlock : sb->getOutputs())
            {
                if(endIfBlock == bb)
                    outputs.push_back(ifBody);
                else
                    outputs.push_back(endIfBlock);
            }

            // Just merge it for the moment
            ifBody->merge(bb);

            delete sb;
            delete t;
        }
    }

    if(!f->getElseBlock()->getChildren().empty())
    {
        // Then create the block where to body will lie
        BasicBlock* elseBody = new BasicBlock();
        conditionBlockOutput->setExitTrue(elseBody);
        if(AstNode* child = f->getElseBlock()->getChildren().front())
        {
            if(Translator * t = getFactory().getTranslator(child, cfg))
            {
                SubGraph* sb = t->translate(table);
                BasicBlock* bb = sb->getInput();

                for(BasicBlock* endElseBlock : sb->getOutputs())
                {
                    if(endElseBlock == bb)
                        outputs.push_back(elseBody);
                    else
                        outputs.push_back(endElseBlock);
                }

                // Just merge it for the moment
                elseBody->merge(bb);

                delete sb;
                delete t;
            }
        }
    }
    else
    {
        outputs.push_back(conditionBlockOutput);
    }

    // Eventually return a subgraph describing what we just created
    return new SubGraph(conditionBlockInput, outputs);
}