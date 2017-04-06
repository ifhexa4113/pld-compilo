#include "FunctionDefinitionTranslator.h"
#include "ast/SymbolTable.h"
#include "ast/declaration/FunctionDeclaration.h"
#include "cfg/FunctionBasicBlock.h"
#include <iostream>

FunctionDefinitionTranslator::FunctionDefinitionTranslator(FunctionDefinition* functionDef, CFG* cfg) : Translator(functionDef, cfg)
{
    // Nothing else to do
}

FunctionDefinitionTranslator::~FunctionDefinitionTranslator()
{
    // Nothing else to do
}

SubGraph * FunctionDefinitionTranslator::translate(Table* table)
{
    // TODO: what about the return ???
    // TODO: handle merging blocks here or after completing the whole cfg ?

    // NOTE: The table MUST be a nullptr.
    //       The BB that will contain de function's label will be the one who
    //       create and destroy the table.
    //       So here we go:
    table = new Table();

    // First cast it in something we can manipulate as we want
    FunctionDefinition* fDef = dynamic_cast<FunctionDefinition*>(node);
    if(fDef == nullptr)
    {
        std::cerr << "FunctionDefinitionTranslator::translate() : ERROR - associated node is not a FunctionDefinition" << std::endl;
        return nullptr;
    }

    SymbolTable st = fDef->getSymbolTable();
    for(auto it = st.begin(); it != st.end(); it++)
    {
        if(auto lvalDecl = dynamic_cast<LValueDeclaration*>(it->second))
        {
            table->getOrCreateRegister(lvalDecl);
        }
    }

    // Then create bases for the subgraph that we'll return
    FunctionBasicBlock* functionBlock = new FunctionBasicBlock(fDef->getName());    // The function block; input of the subgraph
    functionBlock->setTable(table);
    functionBlock->setPrologable(true);
    // NOTE: the two previous lines are ESSENTIAL to avoid memory leaks
    std::vector<BasicBlock*> outputs;                               // The list of subgraph's outputs

    // Then create a variable to memorize the previous block
    std::vector<BasicBlock*> previousBlocks;

    // Add function's arguments
    functionBlock->setArgs(dynamic_cast<FunctionDeclaration*>(fDef->getDeclaration())->getArguments());

    // For each child, link subgraphs
    for(AstNode* child: fDef->getChildren())
    {
        if(Translator * t = getFactory().getTranslator(child, cfg))
        {
            SubGraph* sb = t->translate(table);
            BasicBlock* bb = sb->getInput();

            for(BasicBlock* output: previousBlocks)
            {
                // NOTE: if we're at the first child, this should never be executed
                if(bb->getLabel() == "")
                {
                    // If the next block has no label, then give him one to allow jump
                    bb->giveLabel();
                }
                output->setExitTrue(bb);
            }

            bool updatePrevious = false;
            if(previousBlocks.size() == 0)
            {
                // This is the first child
                if(bb->getLabel() == "")
                {
                    // And it can be merged
                    functionBlock->merge(bb);
                    if(functionBlock->getExitTrue() == nullptr)
                    {
                        previousBlocks.clear();
                        previousBlocks.push_back(functionBlock);
                        updatePrevious = true;
                    }
                }
                else
                {
                    functionBlock->setExitTrue(bb);
                }
            }
            if(!updatePrevious)
                previousBlocks = sb->getOutputs();

            delete sb;
            delete t;
        }
    }

    outputs = previousBlocks;
    // TODO: if there was a return; instruction somewhere else in the rest, we must add it to the outputs ?

    // Return a subgraph describing what we just created
    return new SubGraph(functionBlock, outputs);
}