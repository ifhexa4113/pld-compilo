#include "UnaryBinaryOperationOnVariableTranslator.h"
#include <iostream>
#include "cfg/ir/basic/AddInstruction.h"
#include "cfg/ir/basic/SubInstruction.h"
#include "cfg/ir/basic/MovInstruction.h"
#include "cfg/RegisterInfo.h"
#include "cfg/ir/operand/Register.h"

UnaryBinaryOperationOnVariableTranslator::UnaryBinaryOperationOnVariableTranslator(UnaryBinaryOperationOnVariable* unBinOpV, CFG* cfg) :
        Translator(unBinOpV, cfg)
{
    // Nothing else to do
}

UnaryBinaryOperationOnVariableTranslator::~UnaryBinaryOperationOnVariableTranslator()
{
    // Nothing else to do
}

SubGraph* UnaryBinaryOperationOnVariableTranslator::translate(Table* table)
{
    // First cast it in something we can manipulate as we want
    UnaryBinaryOperationOnVariable* unBinOpV = dynamic_cast<UnaryBinaryOperationOnVariable*>(node);
    if(unBinOpV == nullptr)
    {
        std::cerr << "UnaryBinaryOperationOnVariableTranslator::translate() : ERROR - associated node is not a UnaryBinaryOperationOnVariable" << std::endl;
        return nullptr;
    }

    // Then create bases for the subgraph that we'll return
    BasicBlock* bb = new BasicBlock("");
    std::vector<BasicBlock*> outputs(1, bb);

    Translator* lValExprT = getFactory().getTranslator(unBinOpV->getVariable(), cfg);
    SubGraph* lValExprSb = lValExprT->translate(table);

    switch(unBinOpV->getOperator())
    {
        case UnaryBinaryOperator::INCREMENT_RIGHT:
        {
            Register *reg = table->getOrCreateRegister();
            bb->addInstruction(new MovInstruction(reg, table->getLastDestination(lValExprSb->getOutputs().back())));
            bb->addInstruction(new AddInstruction(
                    table->getLastDestination(lValExprSb->getOutputs().back()),
                    table->getLastDestination(lValExprSb->getOutputs().back()),
                    table->getOrCreateNumberOperand(1)
            ));
            bb->addInstruction(new MovInstruction(reg, reg)); //Update flags
            break;
        }

        case UnaryBinaryOperator::DECREMENT_RIGHT:
        {
            Register *reg = table->getOrCreateRegister();
            bb->addInstruction(new MovInstruction(reg, table->getLastDestination(lValExprSb->getOutputs().back())));
            bb->addInstruction(new SubInstruction(
                    table->getLastDestination(lValExprSb->getOutputs().back()),
                    table->getLastDestination(lValExprSb->getOutputs().back()),
                    table->getOrCreateNumberOperand(1)
            ));
            bb->addInstruction(new MovInstruction(reg, reg));
            break;
        }

        case UnaryBinaryOperator::INCREMENT_LEFT:
            bb->addInstruction(new AddInstruction(
                    table->getLastDestination(lValExprSb->getOutputs().back()),
                    table->getLastDestination(lValExprSb->getOutputs().back()),
                    table->getOrCreateNumberOperand(1)
            ));
            break;

        case UnaryBinaryOperator::DECREMENT_LEFT:
            bb->addInstruction(new SubInstruction(
                    table->getLastDestination(lValExprSb->getOutputs().back()),
                    table->getLastDestination(lValExprSb->getOutputs().back()),
                    table->getOrCreateNumberOperand(1)
            ));
            break;

        case UnaryBinaryOperator::NOT:
        case UnaryBinaryOperator::MINUS:
        case UnaryBinaryOperator::BINARY_NOT:
        default:
            std::cerr << "UnaryBinaryOperationOnVariableTranslator::translate() : ERROR - wrong operator" << std::endl;
            break;
    }

    delete lValExprSb;
    delete lValExprT;

    // Return a subgraph describing what we just created
    return new SubGraph(bb, outputs);
}