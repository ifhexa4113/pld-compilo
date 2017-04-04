#include "CFG.h"
#include "translator/Translator.h"
#include "translator/TranslatorFactory.h"

CFG::CFG(Ast *ast_) : ast(ast_), input(nullptr), blocks()
{
    Translator* t = TranslatorFactory::getFactory().getTranslator(&(ast->getProgram()), this);
    SubGraph* sb = t->translate();
    input = sb->getInput();
    delete sb;
    delete t;
}

CFG::~CFG()
{
    for(BasicBlock* bb: blocks)
    {
        delete bb;
    }
}

BasicBlock* CFG::getInput()
{
    return input;
}

void CFG::addBasicBlock(BasicBlock *block)
{
    blocks.push_back(block);
}

void CFG::print(std::ostream &ost) const
{
    input->print(ost);
}