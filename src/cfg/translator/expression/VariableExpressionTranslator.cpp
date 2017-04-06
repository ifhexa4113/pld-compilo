#include "VariableExpressionTranslator.h"
#include "cfg/ir/basic/MovInstruction.h"
#include "cfg/ir/operand/Register.h"
#include <iostream>

VariableExpressionTranslator::VariableExpressionTranslator(VariableExpression* variableExpression, CFG* cfg) : 
    Translator(variableExpression, cfg)
{
    // Nothing else to do
}

VariableExpressionTranslator::~VariableExpressionTranslator()
{
    // Nothing else to do
}

SubGraph* VariableExpressionTranslator::translate(Table* table)
{
    // First cast it in something we can manipulate as we want
    VariableExpression* varExpr = dynamic_cast<VariableExpression*>(node);
    if(varExpr == nullptr)
    {
        std::cerr << "VariableTranslator::translate() : ERROR - associated node is not a VariableExpression" << std::endl;
        return nullptr;
    }

    // Then create bases for the subgraph that we'll return
    BasicBlock* bb = new BasicBlock("");
    bb->setTable(table);
    std::vector<BasicBlock*> outputs(1, bb);

    Register* variableRegister = table->getRegister(varExpr->getName());

    bb->addInstruction(new MovInstruction(variableRegister, variableRegister));

    // Return a subgraph describing what we just created
    return new SubGraph(bb, outputs);
}