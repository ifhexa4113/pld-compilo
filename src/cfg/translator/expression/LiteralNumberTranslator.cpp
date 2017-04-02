#include "LiteralNumberTranslator.h"
#include "cfg/ir/basic/MovInstruction.h"
#include "cfg/ir/operand/Register.h"
#include "cfg/ir/operand/LiteralNumber.h"
#include <iostream>

LiteralNumberTranslator::LiteralNumberTranslator(LiteralNumberExpression* litNumExp, CFG* cfg) : Translator(litNumExp, cfg)
{
    // Nothing else to do
}

LiteralNumberTranslator::~LiteralNumberTranslator()
{
    // Nothing else to do
}

SubGraph * LiteralNumberTranslator::translate()
{
    // First cast it in something we can manipulate as we want
    LiteralNumberExpression* litNumExpr = dynamic_cast<LiteralNumberExpression*>(node);
    if(litNumExpr == nullptr)
    {
        std::cerr << "LiteralNumberTranslator::translate() : ERROR - associated node is not a LiteralNumberExpression" << std::endl;
        return nullptr;
    }

    // Then create bases for the subgraph that we'll return
    BasicBlock* bb = new BasicBlock("");
    std::vector<BasicBlock*> outputs(1, bb);

    bb->addInstruction(new MovInstruction(new Register(), new LiteralNumber(litNumExpr->getValue())));

    // Return a subgraph describing what we just created
    return new SubGraph(bb, outputs);
}