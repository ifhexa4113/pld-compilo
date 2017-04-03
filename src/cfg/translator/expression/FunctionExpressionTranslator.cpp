#include "FunctionExpressionTranslator.h"
#include "cfg/ir/jump/CallInstruction.h"
#include "cfg/ir/operand/Register.h"
#include "cfg/ir/RegisterInstruction.h"

#include <iostream>

FunctionExpressionTranslator::FunctionExpressionTranslator(FunctionExpression* functionExpression, CFG* cfg) : Translator(functionExpression, cfg)
{
    // Nothing else to do
}

FunctionExpressionTranslator::~FunctionExpressionTranslator()
{
    // Nothing else to do
}

SubGraph * FunctionExpressionTranslator::translate(Table* table)
{
    // First cast it in something we can manipulate as we want
    FunctionExpression* functionExpression = dynamic_cast<FunctionExpression*>(node);
    if(functionExpression == nullptr)
    {
        std::cerr << "FunctionExpressionTranslator::translate() : ERROR - associated node is not a FunctionExpression" << std::endl;
        return nullptr;
    }

    // Then create bases for the subgraph that we'll return
    BasicBlock* bb = new BasicBlock("");
    std::vector<BasicBlock*> outputs(1, bb);

    std::vector<Register*> registers;
    std::vector<Expression*> params = functionExpression->getParameters();

    for (auto param: params){
      Translator* translator = getFactory().getTranslator( param, cfg);
      SubGraph* subGraph = translator->translate(table);

      registers.push_back(dynamic_cast<RegisterInstruction*>(subGraph->getOutputs().back()->getInstructions().back())->getDestination());

      delete translator;
      delete subGraph;
    }

    bb->addInstruction(new CallInstruction(functionExpression->getName(), registers));

    // Return a subgraph describing what we just created
    return new SubGraph(bb, outputs);
}
