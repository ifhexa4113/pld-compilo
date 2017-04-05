#include "BinaryAffectionOperationTranslator.h"
#include "cfg/ir/basic/AddInstruction.h"
#include "cfg/ir/basic/SubInstruction.h"
#include "cfg/ir/basic/MulInstruction.h"
#include "cfg/ir/basic/DivInstruction.h"
#include "cfg/ir/basic/ModInstruction.h"
#include "cfg/ir/basic/MovInstruction.h"
#include "cfg/ir/comp/CmpInstruction.h"
#include "cfg/ir/bitwise/AndInstruction.h"
#include "cfg/ir/bitwise/OrInstruction.h"
#include "cfg/ir/bitwise/XorInstruction.h"
#include "cfg/ir/operand/Register.h"
#include <iostream>

BinaryAffectionOperationTranslator::BinaryAffectionOperationTranslator(BinaryAffectionOperation* binaryAffectionOperation, CFG* cfg) : 
    Translator(binaryAffectionOperation, cfg)
{
    // Nothing else to do
}

BinaryAffectionOperationTranslator::~BinaryAffectionOperationTranslator()
{
    // Nothing else to do
}

SubGraph * BinaryAffectionOperationTranslator::translate(Table* table)
{
    // First cast it in something we can manipulate as we want
    BinaryAffectionOperation* binAffOp = dynamic_cast<BinaryAffectionOperation*>(node);
    if(binAffOp == nullptr)
    {
        std::cerr << "BinaryAffectionOperationTranslator::translate() : ERROR - associated node is not a BinaryArithmeticOperation" << std::endl;
        return nullptr;
    }

    // Then create bases for the subgraph that we'll return
    BasicBlock* bb = new BasicBlock("");
    std::vector<BasicBlock*> outputs(1, bb);

    Translator* rightT = getFactory().getTranslator( binAffOp->getRExpression(), cfg);
    SubGraph* rightSb = rightT->translate(table);
    Translator* leftT = getFactory().getTranslator( binAffOp->getLValue(), cfg);
    SubGraph* leftSb = leftT->translate(table);

    // Merge block of the two expressions
    bb->merge(rightSb->getInput());
    bb->merge(leftSb->getInput());

    switch (binAffOp->getOperator()){
        case AffectionOperator::EQUAL:
            bb->addInstruction(new MovInstruction(
                table->getLastDestination(leftSb->getOutputs().back()),
                table->getLastDestination(rightSb->getOutputs().back())
            ));
            break;

        case AffectionOperator::PLUS_EQUAL:
        {
            Register* lvalueRegister = table->getLastDestination(leftSb->getOutputs().back());
            bb->addInstruction(new AddInstruction(
                lvalueRegister,
                lvalueRegister,
                table->getLastDestination(rightSb->getOutputs().back())
            ));
            break;
        }

        case AffectionOperator::MINUS_EQUAL:
        {
            Register* lvalueRegister = table->getLastDestination(leftSb->getOutputs().back());
            bb->addInstruction(new SubInstruction(
                lvalueRegister,
                lvalueRegister,
                table->getLastDestination(rightSb->getOutputs().back())
            ));
            break;
        }

        case AffectionOperator::MUL_EQUAL:
        {
            Register* lvalueRegister = table->getLastDestination(leftSb->getOutputs().back());
            bb->addInstruction(new MulInstruction(
                lvalueRegister,
                lvalueRegister,
                table->getLastDestination(rightSb->getOutputs().back())
            ));
            break;
        }

        case AffectionOperator::DIV_EQUAL:
        {
            Register* lvalueRegister = table->getLastDestination(leftSb->getOutputs().back());
            bb->addInstruction(new DivInstruction(
                lvalueRegister,
                lvalueRegister,
                table->getLastDestination(rightSb->getOutputs().back())
            ));
            break;
        }
        
        case AffectionOperator::MOD_EQUAL:
        {
            Register* lvalueRegister = table->getLastDestination(leftSb->getOutputs().back());
            bb->addInstruction(new ModInstruction(
                lvalueRegister,
                lvalueRegister,
                table->getLastDestination(rightSb->getOutputs().back())
            ));
            break;
        }
        
        case AffectionOperator::XOR_EQUAL:
        {
            Register* lvalueRegister = table->getLastDestination(leftSb->getOutputs().back());
            bb->addInstruction(new XorInstruction(
                lvalueRegister,
                lvalueRegister,
                table->getLastDestination(rightSb->getOutputs().back())
            ));
            break;
        }
        
        case AffectionOperator::OR_EQUAL:
        {
            Register* lvalueRegister = table->getLastDestination(leftSb->getOutputs().back());
            bb->addInstruction(new OrInstruction(
                lvalueRegister,
                lvalueRegister,
                table->getLastDestination(rightSb->getOutputs().back())
            ));
            break;
        }

        case AffectionOperator::AND_EQUAL:
        {
            Register* lvalueRegister = table->getLastDestination(leftSb->getOutputs().back());
            bb->addInstruction(new AndInstruction(
                lvalueRegister,
                lvalueRegister,
                table->getLastDestination(rightSb->getOutputs().back())
            ));
            break;
        }
    }

    delete leftT;
    delete leftSb;
    delete rightT;
    delete rightSb;

    // Return a subgraph describing what we just created
    return new SubGraph(bb, outputs);
}
