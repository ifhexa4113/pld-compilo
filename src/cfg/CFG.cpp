#include "CFG.h"
#include "translator/Translator.h"
#include "translator/TranslatorFactory.h"

CFG::CFG(Ast *ast_) : ast(ast_), input(nullptr), blocks()
{
    Translator* t = TranslatorFactory::getFactory().getTranslator(&(ast->getProgram()), this);
    input = t->translate()->getInput();
    delete t;
}

CFG::~CFG()
{
    for(BasicBlock* bb: blocks)
    {
        delete bb;
    }
}

void CFG::addBasicBlock(BasicBlock *block)
{
    blocks.push_back(block);
}