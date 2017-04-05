#include <iostream>

#include "BinaryLogicOperationTranslator.h"

#include "cfg/ir/comp/CmpInstruction.h"
#include "cfg/ir/basic/MovInstruction.h"
#include "cfg/ir/operand/Register.h"
#include "cfg/ir/operand/LiteralNumber.h"


BinaryLogicOperationTranslator::BinaryLogicOperationTranslator(BinaryLogicOperation* binaryLogicOperation, CFG* cfg) : 
    Translator(binaryLogicOperation, cfg)
{
    // Nothing else to do
}

BinaryLogicOperationTranslator::~BinaryLogicOperationTranslator()
{
    // Nothing else to do
}

SubGraph* BinaryLogicOperationTranslator::translate(Table* table)
{
    // Cast the node to its original ast node (cf constructor)
    BinaryLogicOperation* binLogOp = dynamic_cast<BinaryLogicOperation*>(node);
    if(binLogOp == nullptr)
    {
        std::cerr << "BinaryLogicOperationTranslator::translate() : ERROR - associated node is not a BinaryLogicOperation" << std::endl;
        return nullptr;
    }

    // Construct blocks for the returned subgraph
    BasicBlock* inputBlock = new BasicBlock("");
    inputBlock->setTable(table);
    // TODO EXPRESSION need a label ?
    BasicBlock* outputBlock = new BasicBlock();
    outputBlock->setTable(table);
    std::vector<BasicBlock*> outputs(1, outputBlock);

    Translator* leftT = getFactory().getTranslator(binLogOp->getLExpression(), cfg);
    SubGraph* leftSb = leftT->translate(table);
    Translator* rightT = getFactory().getTranslator(binLogOp->getRExpression(), cfg);
    SubGraph* rightSb = rightT->translate(table);

    inputBlock->merge(leftSb->getInput());
    inputBlock->merge(rightSb->getInput());

    // Factorise switch code
    BasicBlock* trueBlock = new BasicBlock();
    trueBlock->setTable(table);
    BasicBlock* falseBlock = new BasicBlock();
    falseBlock->setTable(table);
    Register* commonRegister = table->getOrCreateRegister();

    // Add instructions to input and output blocks
    inputBlock->addInstruction(new CmpInstruction(
            table->getLastDestination(leftSb->getOutputs().back()),
            table->getLastDestination(rightSb->getOutputs().back()) ));
    outputBlock->addInstruction(new MovInstruction(commonRegister, commonRegister));

    // Set transition between basic block
    inputBlock->setExitTrue(trueBlock);
    inputBlock->setExitFalse(falseBlock);
    trueBlock->setExitTrue(outputBlock);
    falseBlock->setExitTrue(outputBlock);

    switch(binLogOp->getOperator())
    {
        case LogicOperator::EQUAL:
        {
            trueBlock->addInstruction(new MovInstruction(
                    commonRegister,
                    table->getOrCreateNumberOperand(0)));
            falseBlock->addInstruction(new MovInstruction(
                    commonRegister,
                    table->getOrCreateNumberOperand(1)));
            inputBlock->setExitJumpType(BasicBlock::JumpType::Z);
            break;
        }
        case LogicOperator::NOT_EQUAL:
        {
            trueBlock->addInstruction(new MovInstruction(
                commonRegister, 
                table->getOrCreateNumberOperand(1)));
            falseBlock->addInstruction(new MovInstruction(
                commonRegister, 
                table->getOrCreateNumberOperand(0)));
            inputBlock->setExitJumpType(BasicBlock::JumpType::Z);
            break;
        }
         case LogicOperator::GREATER:
         {

             trueBlock->addInstruction(new MovInstruction(
                     commonRegister,
                     table->getOrCreateNumberOperand(1)));
             falseBlock->addInstruction(new MovInstruction(
                     commonRegister,
                     table->getOrCreateNumberOperand(0)));
             inputBlock->setExitJumpType(BasicBlock::JumpType::NZ);
             break;
         }
         case LogicOperator::GREATER_EQUAL:
         {
             trueBlock->addInstruction(new MovInstruction(
                     commonRegister,
                     table->getOrCreateNumberOperand(1)));
             falseBlock->addInstruction(new MovInstruction(
                     commonRegister,
                     table->getOrCreateNumberOperand(0)));
             inputBlock->setExitJumpType(BasicBlock::JumpType::N);
             break;
         }
         case LogicOperator::LESSER:
         {
             trueBlock->addInstruction(new MovInstruction(
                     commonRegister,
                     table->getOrCreateNumberOperand(0)));
             falseBlock->addInstruction(new MovInstruction(
                     commonRegister,
                     table->getOrCreateNumberOperand(1)));
             inputBlock->setExitJumpType(BasicBlock::JumpType::N);
             break;
         }
         case LogicOperator::LESSER_EQUAL:
         {
             trueBlock->addInstruction(new MovInstruction(
                     commonRegister,
                     table->getOrCreateNumberOperand(0)));
             falseBlock->addInstruction(new MovInstruction(
                     commonRegister,
                     table->getOrCreateNumberOperand(1)));
             inputBlock->setExitJumpType(BasicBlock::JumpType::NZ);
             break;
         }
//         case LogicOperator::AND:
//         {
//             // Create specific object
//             // TODO EXPRESSION need a label ?
//             BasicBlock* firstLevelFalseBlock = new BasicBlock("");
//             BasicBlock* secondLevelFalseBlock = new BasicBlock("");
//             BasicBlock* trueBlock = new BasicBlock("");
//             Register* commonRegister = new Register();
//
//             // Add their instruction to each block
//             inputBlock->addInstruction(new CmpInstruction(new Register( *(dynamic_cast<RegisterInstruction*>(leftSb->getOutputs().back()->getInstructions().back())->getDestination() ) ),
//                                                           new LiteralNumber(0) ));
//
//             firstLevelFalseBlock->addInstruction(new CmpInstruction(new Register( *(dynamic_cast<RegisterInstruction*>(rightSb->getOutputs().back()->getInstructions().back())->getDestination() ) ),
//                                                                     new LiteralNumber(0) ));
//
//             secondLevelFalseBlock->addInstruction(new MovInstruction(commonRegister, new LiteralNumber(1)));
//             trueBlock->addInstruction(new MovInstruction(commonRegister, new LiteralNumber(0)));
//
//             outputBlock->addInstruction(new MovInstruction(commonRegister, commonRegister));
//
//             // Set transition between basic block
//             inputBlock->setExitTrue(trueBlock);
//             inputBlock->setExitFalse(firstLevelFalseBlock);
//             inputBlock->setExitJumpType(BasicBlock::JumpType::Z);
//
//             firstLevelFalseBlock->setExitTrue(trueBlock);
//             firstLevelFalseBlock->setExitFalse(secondLevelFalseBlock);
//
//             secondLevelFalseBlock->setExitTrue(outputBlock);
//             trueBlock->setExitTrue(outputBlock);
//
//             break;
//         }
//         case LogicOperator::OR:
//         {
//             // Create specific object
//             // TODO EXPRESSION need a label ?
//             BasicBlock* firstLevelTrueBlock = new BasicBlock("");
//             BasicBlock* secondLevelTrueBlock = new BasicBlock("");
//             BasicBlock* falseBlock = new BasicBlock("");
//             Register* commonRegister = new Register();
//
//             // Add their instruction to each block
//             inputBlock->addInstruction(new CmpInstruction(new Register( *(dynamic_cast<RegisterInstruction*>(leftSb->getOutputs().back()->getInstructions().back())->getDestination() ) ),
//                                                           new LiteralNumber(0) ));
//
//             firstLevelTrueBlock->addInstruction(new CmpInstruction(new Register( *(dynamic_cast<RegisterInstruction*>(rightSb->getOutputs().back()->getInstructions().back())->getDestination() ) ),
//                                                                    new LiteralNumber(0) ));
//
//             secondLevelTrueBlock->addInstruction(new MovInstruction(commonRegister, new LiteralNumber(0)));
//             falseBlock->addInstruction(new MovInstruction(commonRegister, new LiteralNumber(1)));
//
//             outputBlock->addInstruction(new MovInstruction(commonRegister, commonRegister));
//
//             // Set transition between basic block
//             inputBlock->setExitTrue(firstLevelTrueBlock);
//             inputBlock->setExitFalse(falseBlock);
//             inputBlock->setExitJumpType(BasicBlock::JumpType::Z);
//
//             firstLevelTrueBlock->setExitTrue(secondLevelTrueBlock);
//             firstLevelTrueBlock->setExitFalse(falseBlock);
//
//             secondLevelTrueBlock->setExitTrue(outputBlock);
//             falseBlock->setExitTrue(outputBlock);
//
//             break;
//         }
    }

    delete leftT;
    delete leftSb;
    delete rightT;
    delete rightSb;

    // Return a subgraph describing what we just created
    return new SubGraph(inputBlock, outputs);
}