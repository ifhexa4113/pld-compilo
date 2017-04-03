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
    std::vector<BasicBlock*> outputs(1, bb);

    Translator* leftT = getFactory().getTranslator(binBinOp->getLExpression(), cfg);
    SubGraph* leftSb = leftT->translate(table);
    Translator* rightT = getFactory().getTranslator(binBinOp->getRExpression(), cfg);
    SubGraph* rightSb = rightT->translate(table);

    switch(binBinOp->getOperator())
    {
    case BinaryBinaryOperator::XOR:
        bb->addInstruction(new XorInstruction(new Register(),
                                              new Register( *(dynamic_cast<RegisterInstruction*>(leftSb->getOutputs().back()->getInstructions().back())->getDestination() ) ),
                                              new Register( *(dynamic_cast<RegisterInstruction*>(rightSb->getOutputs().back()->getInstructions().back())->getDestination() ) ) ));

        break;
    case BinaryBinaryOperator::OR:
        bb->addInstruction(new OrInstruction(new Register(),
                                              new Register( *(dynamic_cast<RegisterInstruction*>(leftSb->getOutputs().back()->getInstructions().back())->getDestination() ) ),
                                              new Register( *(dynamic_cast<RegisterInstruction*>(rightSb->getOutputs().back()->getInstructions().back())->getDestination() ) ) ));
        break;
    case BinaryBinaryOperator::AND:
        bb->addInstruction(new AndInstruction(new Register(),
                                              new Register( *(dynamic_cast<RegisterInstruction*>(leftSb->getOutputs().back()->getInstructions().back())->getDestination() ) ),
                                              new Register( *(dynamic_cast<RegisterInstruction*>(rightSb->getOutputs().back()->getInstructions().back())->getDestination() ) ) ));
        break;
    case BinaryBinaryOperator::LEFT_SHIFT:
        bb->addInstruction(new LshiftInstruction(new Register(),
                                              new Register( *(dynamic_cast<RegisterInstruction*>(leftSb->getOutputs().back()->getInstructions().back())->getDestination() ) ),
                                              new Register( *(dynamic_cast<RegisterInstruction*>(rightSb->getOutputs().back()->getInstructions().back())->getDestination() ) ) ));
        break;
    case BinaryBinaryOperator::RIGHT_SHIFT:
        bb->addInstruction(new RshiftInstruction(new Register(),
                                              new Register( *(dynamic_cast<RegisterInstruction*>(leftSb->getOutputs().back()->getInstructions().back())->getDestination() ) ),
                                              new Register( *(dynamic_cast<RegisterInstruction*>(rightSb->getOutputs().back()->getInstructions().back())->getDestination() ) ) ));
        break;
    }
    delete leftT;
    delete leftSb;
    delete rightT;
    delete rightSb;

    // Return a subgraph describing what we just created
    return new SubGraph(bb, outputs);
}