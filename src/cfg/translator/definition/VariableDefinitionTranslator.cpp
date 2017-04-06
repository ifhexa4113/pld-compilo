#include "VariableDefinitionTranslator.h"
#include <iostream>
#include "cfg/ir/RegisterInstruction.h"
#include "cfg/ir/basic/MovInstruction.h"
#include "cfg/ir/operand/Register.h"

VariableDefinitionTranslator::VariableDefinitionTranslator(VariableDefinition *variableDef, CFG *cfg) :
    Translator(variableDef, cfg)
{
    // Nothing else to do
}

VariableDefinitionTranslator::~VariableDefinitionTranslator()
{
    // Nothing else to do
}

SubGraph * VariableDefinitionTranslator::translate(Table* table)
{
    // First cast it in something we can manipulate as we want
    VariableDefinition* vDef = dynamic_cast<VariableDefinition*>(node);
    if(vDef == nullptr)
    {
        std::cerr << "VariableDefinitionTranslator::translate() : ERROR - associated node is not a VariableDefinition" << std::endl;
        return nullptr;
    }

    Translator* exprTranslator = getFactory().getTranslator(vDef->getRExpression(), cfg);
    SubGraph* sb = exprTranslator->translate(table);

    // At this point, we are sure that sb only contains one basic block
    // This basic block contains the code needed to evaluate the expression
    // The last instruction's destination contains the evaluated expression
    BasicBlock* expr = sb->getInput();

    // Add the instruction
    expr->addInstruction(new MovInstruction(
        table->getOrCreateRegister(vDef->getDeclaration()),
        table->getLastDestination(expr)
    ));

    // Return a subgraph describing what we just created
    return new SubGraph(expr, std::vector<BasicBlock*>(1, expr));
}