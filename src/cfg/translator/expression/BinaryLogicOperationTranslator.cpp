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

    // Construct blocks for the return subgraph
    BasicBlock* inputBlock = new BasicBlock("");
    // TODO EXPRESSION need a label ?
    BasicBlock* outputBlock = new BasicBlock();
    std::vector<BasicBlock*> outputs(1, outputBlock);

    Translator* leftT = getFactory().getTranslator(binLogOp->getLExpression(), cfg);
    SubGraph* leftSb = leftT->translate(table);
    Translator* rightT = getFactory().getTranslator(binLogOp->getRExpression(), cfg);
    SubGraph* rightSb = rightT->translate(table);

    inputBlock->merge(leftSb->getInput());
    inputBlock->merge(rightSb->getInput());

    Register* commonRegister = table->getOrCreateRegister();
    switch(binLogOp->getOperator())
    {
        case LogicOperator::EQUAL:
        {
            // Create specific object
            // TODO EXPRESSION need a label ?
            BasicBlock* trueBlock = new BasicBlock();
            BasicBlock* falseBlock = new BasicBlock();

            // Add their instructtion to each block
            inputBlock->addInstruction(new CmpInstruction(
                table->getLastDestination(leftSb->getOutputs().back()),
                table->getLastDestination(rightSb->getOutputs().back())));
            
            trueBlock->addInstruction(new MovInstruction(commonRegister, new LiteralNumber(1)));
            falseBlock->addInstruction(new MovInstruction(commonRegister, new LiteralNumber(0)));

            // TODO EXPRESSION create a new register ?
            outputBlock->addInstruction(new MovInstruction(commonRegister, commonRegister));
                            
            // Set transition between basic block
            inputBlock->setExitTrue(trueBlock);
            inputBlock->setExitFalse(falseBlock);
            inputBlock->setExitJumpType(BasicBlock::JumpType::Z);

            trueBlock->setExitTrue(outputBlock);
            falseBlock->setExitTrue(outputBlock);

            break;
        }
        case LogicOperator::GREATER:
        {
            // Create specific object
            // TODO EXPRESSION need a label ?
            BasicBlock* trueBlock = new BasicBlock();
            BasicBlock* falseBlock = new BasicBlock();

            // Add their instructtion to each block
            inputBlock->addInstruction(new CmpInstruction(
                table->getLastDestination(leftSb->getOutputs().back()),
                table->getLastDestination(rightSb->getOutputs().back())));
            
            trueBlock->addInstruction(new MovInstruction(commonRegister, new LiteralNumber(1)));
            falseBlock->addInstruction(new MovInstruction(commonRegister, new LiteralNumber(0)));

            // TODO EXPRESSION create a new register ?
            outputBlock->addInstruction(new MovInstruction(commonRegister, commonRegister));
                            
            // Set transition between basic block
            inputBlock->setExitTrue(trueBlock);
            inputBlock->setExitFalse(falseBlock);
            inputBlock->setExitJumpType(BasicBlock::JumpType::NZ);

            trueBlock->setExitTrue(outputBlock);
            falseBlock->setExitTrue(outputBlock);

            break;
        }

        case LogicOperator::GREATER_EQUAL:
        {
            // Create specific object
            // TODO EXPRESSION need a label ?
            BasicBlock* trueBlock = new BasicBlock();
            BasicBlock* falseBlock = new BasicBlock();

            // Add their instructtion to each block
            inputBlock->addInstruction(new CmpInstruction(
                table->getLastDestination(leftSb->getOutputs().back()),
                table->getLastDestination(rightSb->getOutputs().back())));
            
            trueBlock->addInstruction(new MovInstruction(commonRegister, new LiteralNumber(1)));
            falseBlock->addInstruction(new MovInstruction(commonRegister, new LiteralNumber(0)));

            // TODO EXPRESSION create a new register ?
            outputBlock->addInstruction(new MovInstruction(commonRegister, commonRegister));
                            
            // Set transition between basic block
            inputBlock->setExitTrue(trueBlock);
            inputBlock->setExitFalse(falseBlock);
            inputBlock->setExitJumpType(BasicBlock::JumpType::N);

            trueBlock->setExitTrue(outputBlock);
            falseBlock->setExitTrue(outputBlock);

            break;
        }

        case LogicOperator::LESSER:
        {
            // Create specific object
            // TODO EXPRESSION need a label ?
            BasicBlock* trueBlock = new BasicBlock();
            BasicBlock* falseBlock = new BasicBlock();

            // Add their instructtion to each block
            inputBlock->addInstruction(new CmpInstruction(
                table->getLastDestination(leftSb->getOutputs().back()),
                table->getLastDestination(rightSb->getOutputs().back())));
            
            trueBlock->addInstruction(new MovInstruction(commonRegister, new LiteralNumber(0)));
            falseBlock->addInstruction(new MovInstruction(commonRegister, new LiteralNumber(1)));

            // TODO EXPRESSION create a new register ?
            outputBlock->addInstruction(new MovInstruction(commonRegister, commonRegister));
                            
            // Set transition between basic block
            inputBlock->setExitTrue(trueBlock);
            inputBlock->setExitFalse(falseBlock);
            inputBlock->setExitJumpType(BasicBlock::JumpType::N);

            trueBlock->setExitTrue(outputBlock);
            falseBlock->setExitTrue(outputBlock);

            break;
        }

        case LogicOperator::LESSER_EQUAL:
        {
            // Create specific object
            // TODO EXPRESSION need a label ?
            BasicBlock* trueBlock = new BasicBlock();
            BasicBlock* falseBlock = new BasicBlock();

            // Add their instructtion to each block
            inputBlock->addInstruction(new CmpInstruction(
                table->getLastDestination(leftSb->getOutputs().back()),
                table->getLastDestination(rightSb->getOutputs().back())));
            
            trueBlock->addInstruction(new MovInstruction(commonRegister, new LiteralNumber(0)));
            falseBlock->addInstruction(new MovInstruction(commonRegister, new LiteralNumber(1)));

            // TODO EXPRESSION create a new register ?
            outputBlock->addInstruction(new MovInstruction(commonRegister, commonRegister));
                            
            // Set transition between basic block
            inputBlock->setExitTrue(trueBlock);
            inputBlock->setExitFalse(falseBlock);
            inputBlock->setExitJumpType(BasicBlock::JumpType::NZ);

            trueBlock->setExitTrue(outputBlock);
            falseBlock->setExitTrue(outputBlock);

            break;
        }
        case LogicOperator::NOT_EQUAL:
                {
            // Create specific object
            // TODO EXPRESSION need a label ?
            BasicBlock* trueBlock = new BasicBlock();
            BasicBlock* falseBlock = new BasicBlock();

            // Add their instructtion to each block
            inputBlock->addInstruction(new CmpInstruction(
                table->getLastDestination(leftSb->getOutputs().back()),
                table->getLastDestination(rightSb->getOutputs().back())));
            
            trueBlock->addInstruction(new MovInstruction(commonRegister, new LiteralNumber(0)));
            falseBlock->addInstruction(new MovInstruction(commonRegister, new LiteralNumber(1)));

            // TODO EXPRESSION create a new register ?
            outputBlock->addInstruction(new MovInstruction(commonRegister, commonRegister));
                            
            // Set transition between basic block
            inputBlock->setExitTrue(trueBlock);
            inputBlock->setExitFalse(falseBlock);
            inputBlock->setExitJumpType(BasicBlock::JumpType::Z);

            trueBlock->setExitTrue(outputBlock);
            falseBlock->setExitTrue(outputBlock);

            break;
        }
        case LogicOperator::AND:
        {
            // Create specific object
            // TODO EXPRESSION need a label ?
            BasicBlock* firstLevelFalseBlock = new BasicBlock();
            BasicBlock* secondLevelFalseBlock = new BasicBlock();
            BasicBlock* trueBlock = new BasicBlock();

            // Add their instruction to each block
            inputBlock->addInstruction(new CmpInstruction(
                table->getLastDestination(leftSb->getOutputs().back()),
                new LiteralNumber(0) ));

            firstLevelFalseBlock->addInstruction(new CmpInstruction(
                table->getLastDestination(rightSb->getOutputs().back()),
                new LiteralNumber(0) ));

            secondLevelFalseBlock->addInstruction(new MovInstruction(commonRegister, new LiteralNumber(1)));
            trueBlock->addInstruction(new MovInstruction(commonRegister, new LiteralNumber(0)));
            
            outputBlock->addInstruction(new MovInstruction(commonRegister, commonRegister));

            // Set transition between basic block
            inputBlock->setExitTrue(trueBlock);
            inputBlock->setExitFalse(firstLevelFalseBlock);
            inputBlock->setExitJumpType(BasicBlock::JumpType::Z);

            firstLevelFalseBlock->setExitTrue(trueBlock);
            firstLevelFalseBlock->setExitFalse(secondLevelFalseBlock);

            secondLevelFalseBlock->setExitTrue(outputBlock);
            trueBlock->setExitTrue(outputBlock);

            break;
        }
        case LogicOperator::OR:
        {
            // Create specific object
            // TODO EXPRESSION need a label ?
            BasicBlock* firstLevelTrueBlock = new BasicBlock();
            BasicBlock* secondLevelTrueBlock = new BasicBlock();
            BasicBlock* falseBlock = new BasicBlock();

            // Add their instruction to each block
            inputBlock->addInstruction(new CmpInstruction(
                table->getLastDestination(leftSb->getOutputs().back()),
                new LiteralNumber(0) ));

            firstLevelTrueBlock->addInstruction(new CmpInstruction(
                table->getLastDestination(rightSb->getOutputs().back()),
                new LiteralNumber(0) ));

            secondLevelTrueBlock->addInstruction(new MovInstruction(commonRegister, new LiteralNumber(0)));
            falseBlock->addInstruction(new MovInstruction(commonRegister, new LiteralNumber(1)));
            
            outputBlock->addInstruction(new MovInstruction(commonRegister, commonRegister));

            // Set transition between basic block
            inputBlock->setExitTrue(firstLevelTrueBlock);
            inputBlock->setExitFalse(falseBlock);
            inputBlock->setExitJumpType(BasicBlock::JumpType::Z);

            firstLevelTrueBlock->setExitTrue(secondLevelTrueBlock);
            firstLevelTrueBlock->setExitFalse(falseBlock);

            secondLevelTrueBlock->setExitTrue(outputBlock);
            falseBlock->setExitTrue(outputBlock);

            break;
        }
    }
    delete leftT;
    delete leftSb;
    delete rightT;
    delete rightSb;

    // Return a subgraph describing what we just created
    return new SubGraph(inputBlock, outputs);
}