#include <iostream>

#include "BinaryBinaryOperationTranslator.h"
#include "cfg/ir/bitwise/XorInstruction.h"
#include "cfg/ir/bitwise/OrInstruction.h"
#include "cfg/ir/bitwise/AndInstruction.h"
#include "cfg/ir/bitwise/LshiftInstruction.h"
#include "cfg/ir/bitwise/RshiftInstruction.h"
#include "cfg/ir/operand/Register.h"

BinaryBinaryOperationTranslator::BinaryBinaryOperationTranslator(BinaryBinaryOperation* binaryBinaryOperation, CFG* cfg) : 
    Translator(binaryBinaryOperation, cfg)
{
    // Nothing else to do
}

BinaryBinaryOperationTranslator::~BinaryBinaryOperationTranslator()
{
    // Nothing else to do
}

SubGraph* BinaryBinaryOperationTranslator::translate(Table* table)
{
    // Cast the node to its original ast node (cf constructor)
    BinaryBinaryOperation* binBinOp = dynamic_cast<BinaryBinaryOperation*>(node);
    if(binBinOp == nullptr)
    {
        std::cerr << "BinaryBinaryOperationTranslator::translate() : ERROR - associated node is not a BinaryBinaryOperation" << std::endl;
        return nullptr;
    }

    // Construct blocks for the return subgraph
    BasicBlock* bb = new BasicBlock("");
    bb->setTable(table);
    std::vector<BasicBlock*> outputs(1, bb);

    Translator* leftT = getFactory().getTranslator(binBinOp->getLExpression(), cfg);
    SubGraph* leftSb = leftT->translate(table);
    Translator* rightT = getFactory().getTranslator(binBinOp->getRExpression(), cfg);
    SubGraph* rightSb = rightT->translate(table);

    // Merge block of the two expressions
    bb->merge(leftSb->getInput());
    bb->merge(rightSb->getInput());

    switch(binBinOp->getOperator())
    {
    case BinaryBinaryOperator::XOR:
        bb->addInstruction(new XorInstruction(
            table->getOrCreateRegister(),
            table->getLastDestination(leftSb->getOutputs().back()),
            table->getLastDestination(rightSb->getOutputs().back())
        ));
        break;

    case BinaryBinaryOperator::OR:
        bb->addInstruction(new OrInstruction(
            table->getOrCreateRegister(),
            table->getLastDestination(leftSb->getOutputs().back()),
            table->getLastDestination(rightSb->getOutputs().back())
        ));
        break;

    case BinaryBinaryOperator::AND:
        bb->addInstruction(new AndInstruction(
            table->getOrCreateRegister(),
            table->getLastDestination(leftSb->getOutputs().back()),
            table->getLastDestination(rightSb->getOutputs().back())
        ));
        break;

    case BinaryBinaryOperator::LEFT_SHIFT:
        bb->addInstruction(new LshiftInstruction(
            table->getOrCreateRegister(),
            table->getLastDestination(leftSb->getOutputs().back()),
            table->getLastDestination(rightSb->getOutputs().back())
        ));
        break;
    case BinaryBinaryOperator::RIGHT_SHIFT:
        bb->addInstruction(new RshiftInstruction(
            table->getOrCreateRegister(),
            table->getLastDestination(leftSb->getOutputs().back()),
            table->getLastDestination(rightSb->getOutputs().back())
        ));
        break;
    }
    delete leftT;
    delete leftSb;
    delete rightT;
    delete rightSb;

    // Return a subgraph describing what we just created
    return new SubGraph(bb, outputs);
}