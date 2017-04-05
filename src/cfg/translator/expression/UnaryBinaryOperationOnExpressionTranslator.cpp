#include "UnaryBinaryOperationOnExpressionTranslator.h"
#include <iostream>
#include "cfg/ir/basic/SubInstruction.h"
#include "cfg/ir/bitwise/NotInstruction.h"

UnaryBinaryOperationOnExpressionTranslator::UnaryBinaryOperationOnExpressionTranslator(UnaryBinaryOperationOnExpression* unBinOpE, CFG* cfg) :
        Translator(unBinOpE, cfg)
{
    // Nothing else to do
}

UnaryBinaryOperationOnExpressionTranslator::~UnaryBinaryOperationOnExpressionTranslator()
{
    // Nothing else to do
}

SubGraph* UnaryBinaryOperationOnExpressionTranslator::translate(Table* table)
{
    // First cast it in something we can manipulate as we want
    UnaryBinaryOperationOnExpression* unBinOpE = dynamic_cast<UnaryBinaryOperationOnExpression*>(node);
    if(unBinOpE == nullptr)
    {
        std::cerr << "UnaryBinaryOperationOnExpressionTranslator::translate() : ERROR - associated node is not a UnaryBinaryOperationOnExpression" << std::endl;
        return nullptr;
    }

    // Then create bases for the subgraph that we'll return
    BasicBlock* bb = new BasicBlock("");
    std::vector<BasicBlock*> outputs(1, bb);

    Translator* exprT = getFactory().getTranslator(unBinOpE->getExpression(), cfg);
    SubGraph* exprSb = exprT->translate(table);

    switch(unBinOpE->getOperator())
    {
        case UnaryBinaryOperator::NOT: //TODO

            break;

        case UnaryBinaryOperator::MINUS:
            bb->addInstruction(new SubInstruction(
                    table->getLastDestination(exprSb->getOutputs().back()),
                    table->getOrCreateNumberOperand(0),
                    table->getLastDestination(exprSb->getOutputs().back())
            ));
            break;

        case UnaryBinaryOperator::BINARY_NOT:
            bb->addInstruction(new NotInstruction(
                    table->getLastDestination(exprSb->getOutputs().back()),
                    table->getLastDestination(exprSb->getOutputs().back())
            ));
            break;

        case UnaryBinaryOperator::INCREMENT_RIGHT:
        case UnaryBinaryOperator::DECREMENT_RIGHT:
        case UnaryBinaryOperator::INCREMENT_LEFT:
        case UnaryBinaryOperator::DECREMENT_LEFT:
        default:
            std::cerr << "UnaryBinaryOperationOnExpressionTranslator::translate() : ERROR - wrong operator" << std::endl;
            break;
    }

    delete exprSb;
    delete exprT;

    // Return a subgraph describing what we just created
    return new SubGraph(bb, outputs);
}