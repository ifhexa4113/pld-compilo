#include "BinaryArithmeticOperationTranslator.h"
#include <iostream>

BinaryArithmeticOperationTranslator::BinaryArithmeticOperationTranslator(LiteralNumberExpression* literalNumberExpression, CFG* cfg) : Translator(literalNumberExpression, cfg)
{
    // Nothing else to do
}

BinaryArithmeticOperationTranslator::~BinaryArithmeticOperationTranslator()
{
    // Nothing else to do
}

SubGraph * BinaryArithmeticOperationTranslator::translate()
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

    Translator* leftT = getFactory().getTranslator( binArithOp->getLExpression, cfg);
    Subgraph* leftSb = t->translate();
    Translator* rightT = getFactory().getTranslator( binArithOp->getLExpression, cfg);
    Subgraph* rightSb = t->translate();

    switch (binArithOp->getOperator){
        case PLUS:
            bb->addInstruction(new AddInstruction(new Register(),
                                                  new Register(*(dynamic_cast<RegisterInstruction*>(leftSb->getOutputs().back()->getInstructions().back())->getDestionation)),
                                                  new Register(*(dynamic_cast<RegisterInstruction*>(rightSb->getOutputs().back()->getInstructions().back())->getDestionation))));
            break;
        case MINUS:
            bb->addInstruction(new SubInstruction(new Register(),
                                                  new Register(*(dynamic_cast<RegisterInstruction*>(leftSb->getOutputs().back()->getInstructions().back())->getDestionation)),
                                                  new Register(*(dynamic_cast<RegisterInstruction*>(rightSb->getOutputs().back()->getInstructions().back())->getDestionation))));
            break;
        case MUL:
            bb->addInstruction(new MulInstruction(new Register(),
                                                  new Register(*(dynamic_cast<RegisterInstruction*>(leftSb->getOutputs().back()->getInstructions().back())->getDestionation)),
                                                  new Register(*(dynamic_cast<RegisterInstruction*>(rightSb->getOutputs().back()->getInstructions().back())->getDestionation))));
            break;
        case DIV:
            bb->addInstruction(new DivInstruction(new Register(),
                                                  new Register(*(dynamic_cast<RegisterInstruction*>(leftSb->getOutputs().back()->getInstructions().back())->getDestionation)),
                                                  new Register(*(dynamic_cast<RegisterInstruction*>(rightSb->getOutputs().back()->getInstructions().back())->getDestionation))));
            break;
        case MOD:
            bb->addInstruction(new ModInstruction(new Register(),
                                                  new Register(*(dynamic_cast<RegisterInstruction*>(leftSb->getOutputs().back()->getInstructions().back())->getDestionation)),
                                                  new Register(*(dynamic_cast<RegisterInstruction*>(rightSb->getOutputs().back()->getInstructions().back())->getDestionation))));
            break;
    }


    // Return a subgraph describing what we just created
    return new SubGraph(bb, outputs);
}
