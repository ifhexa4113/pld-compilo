#include "VariableDefinitionTranslator.h"
#include <iostream>
#include "cfg/ir/RegisterInstruction.h"
#include "cfg/ir/MovInstruction.h"
#include "cfg/ir/Register.h"

VariableDefinitionTranslator::VariableDefinitionTranslator(VariableDefinition *variableDef, CFG *cfg) :
    Translator(variableDef, cfg)
{
    // Nothing else to do
}

VariableDefinitionTranslator::~VariableDefinitionTranslator()
{
    // Nothing else to do
}

SubGraph * VariableDefinitionTranslator::translate()
{
    // First cast it in something we can manipulate as we want
    VariableDefinition* vDef = dynamic_cast<VariableDefinition*>(node);
    if(vDef == nullptr)
    {
        std::cerr << "VariableDefinitionTranslator::translate() : ERROR - associated node is not a VariableDefinition" << std::endl;
        return nullptr;
    }

    // Create the BasicBlock that will contain, at first, the variable definition
    // TODO: give it a name ?
    BasicBlock* bb = new BasicBlock("");

    Translator* exprTranslator = getFactory().getTranslator(vDef->getRExpression(), cfg);
    SubGraph* sb = exprTranslator->translate();

    // At this point, we are sure that sb only contains one basic block
    // This basic block contains the code needed to evaluate the expression
    // The last instruction's destination contains the evaluated expression
    BasicBlock* expr = sb->getInput();
    expr->setExitTrue(bb);

    // Add the instruction
    bb->addInstruction(new MovInstruction(new Register(), new Register(*(dynamic_cast<RegisterInstruction*>(bb->getInstructions().back())->getDestination()))));

    // Return a subgraph describing what we just created
    return new SubGraph(bb, std::vector<BasicBlock*>());
}