#include "BinaryArithmeticOperationTranslator.h"
#include "cfg/ir/basic/AddInstruction.h"
#include "cfg/ir/basic/SubInstruction.h"
#include "cfg/ir/basic/MulInstruction.h"
#include "cfg/ir/basic/DivInstruction.h"
#include "cfg/ir/basic/ModInstruction.h"
#include "cfg/ir/operand/Register.h"
#include <iostream>

BinaryArithmeticOperationTranslator::BinaryArithmeticOperationTranslator(BinaryArithmeticOperation* binaryArithmeticOperation, CFG* cfg) : Translator(binaryArithmeticOperation, cfg)
{
    // Nothing else to do
}

BinaryArithmeticOperationTranslator::~BinaryArithmeticOperationTranslator()
{
    // Nothing else to do
}

SubGraph * BinaryArithmeticOperationTranslator::translate(Table* table)
{
    // First cast it in something we can manipulate as we want
    BinaryArithmeticOperation* binArithOp = dynamic_cast<BinaryArithmeticOperation*>(node);
    if(binArithOp == nullptr)
    {
        std::cerr << "BinaryArithmeticOperationTranslator::translate() : ERROR - associated node is not a BinaryArithmeticOperation" << std::endl;
        return nullptr;
    }

    // Then create bases for the subgraph that we'll return
    BasicBlock* bb = new BasicBlock("");
    std::vector<BasicBlock*> outputs(1, bb);

    Translator* leftT = getFactory().getTranslator( binArithOp->getLExpression(), cfg);
    SubGraph* leftSb = leftT->translate(table);
    Translator* rightT = getFactory().getTranslator( binArithOp->getRExpression(), cfg);
    SubGraph* rightSb = rightT->translate(table);

    // Merge block of the two expressions
    bb->merge(leftSb->getInput());
    bb->merge(rightSb->getInput());

    switch (binArithOp->getOperator()){
        case ArithmeticOperator::PLUS:
            bb->addInstruction(new AddInstruction(
                table->getOrCreateRegister(),
                table->getLastDestination(leftSb->getOutputs().back()),
                table->getLastDestination(rightSb->getOutputs().back())
            ));
            break;

        case ArithmeticOperator::MINUS:
            bb->addInstruction(new SubInstruction(
                table->getOrCreateRegister(),
                table->getLastDestination(leftSb->getOutputs().back()),
                table->getLastDestination(rightSb->getOutputs().back())
            ));
            break;

        case ArithmeticOperator::MUL:
            bb->addInstruction(new MulInstruction(
                table->getOrCreateRegister(),
                table->getLastDestination(leftSb->getOutputs().back()),
                table->getLastDestination(rightSb->getOutputs().back())
            ));
            break;

        case ArithmeticOperator::DIV:
            bb->addInstruction(new DivInstruction(
                table->getOrCreateRegister(),
                table->getLastDestination(leftSb->getOutputs().back()),
                table->getLastDestination(rightSb->getOutputs().back())
            ));
            break;

        case ArithmeticOperator::MOD:
            bb->addInstruction(new ModInstruction(
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
