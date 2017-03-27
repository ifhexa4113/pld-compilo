#include "CmmProgramTranslator.h"
#include <iostream>

CmmProgramTranslator::CmmProgramTranslator(CmmProgram* program, CFG* cfg) : Translator(program, cfg)
{
    // Nothing else to do
}

CmmProgramTranslator::~CmmProgramTranslator()
{
    // Nothing else to do
}

BasicBlock * CmmProgramTranslator::translate()
{
    CmmProgram* cmmProgram = dynamic_cast<CmmProgram*>(node);
    if(cmmProgram == nullptr)
    {
        std::cerr << "CmmProgramTranslator::translate() : ERROR - associated node is not a CmmProgram" << std::endl;
        return nullptr;
    }
    for(AstNode* child: cmmProgram->getChildren())
    {
        Translator * t = getFactory().getTranslator(child, cfg);
        BasicBlock* bb = t->translate();
        if(bb != nullptr)
        {
            cfg->addBasicBlock(bb);
        }
        else
        {
            std::cout << "CmmProgramTranslator::translate() : a basic block was null!" << std::endl;
        }
        delete t;
    }

    // No need to return anything here, we're at the top
    return nullptr;
}