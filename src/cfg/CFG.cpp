#include "CFG.h"
#include "translator/Translator.h"
#include "translator/TranslatorFactory.h"

CFG::CFG(Ast *ast_) : ast(ast_), input(nullptr)
{
    Translator* t = TranslatorFactory::getFactory().getTranslator(&(ast->getProgram()), this);
    SubGraph* sb = t->translate();
    input = sb->getInput();
    delete sb;
    delete t;
}

CFG::~CFG()
{
    // TODO: oops, it's kinda complicated to delete
    //       But at the moment, there are memory leaks
//    if(input)
//    {
//        delete input;
//    }
}

BasicBlock* CFG::getInput()
{
    return input;
}

void CFG::print(std::ostream &ost) const
{
    input->print(ost);
}