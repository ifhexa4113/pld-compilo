#include "CFG.h"
#include "translator/Translator.h"
#include "translator/TranslatorFactory.h"

#include <map>
#include <functional>

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
    // So we need to delete this graph.
    // We can't do that properly based on each BB destructor,
    // so we're gonna do this here.

    // We just need a UNIQUE pointer to each BB in the graph.
    // We gonna store them in the following map
    // (easy and low cost check if it already exists).
    std::map<BasicBlock*, BasicBlock*> deleteMap;

    // Now we need a function to gather all BB.
    // It's really dedicated to the destructor,
    // so we want to keep it here; but C++ doesn't allow us to define
    // a function here.
    // Never mind, we're gonna use a lambda.
    // But we want to use it recursively and therefore we need to capture
    // the lambda itself. So we ca'nt use auto because the type won't
    // be evaluated when needed. So we just use a std::function wrapper.
    std::function<void(std::map<BasicBlock*, BasicBlock*>&, BasicBlock*)> f = [&f](std::map<BasicBlock*, BasicBlock*>& m, BasicBlock* bb) {
        if(m.count(bb) == 0)
        {
            // Insert it if not already seen
            m.insert(std::make_pair(bb, bb));
            if(bb->getExitTrue())
            {
                // Has an exitTrue pointer ? Gather it
                f(m, bb->getExitTrue());
            }
            if(bb->getExitFalse())
            {
                // Has an exitFalse pointer ? Gather it
                f(m, bb->getExitFalse());
            }
        }
        // Already now the BB, pass
    };

    // And let's gather these BBs !
    f(deleteMap, input);

    // Eventually, just delete them
    for(auto it = deleteMap.begin(); it != deleteMap.end(); it++)
    {
        delete it->first;
    }
}

BasicBlock* CFG::getInput()
{
    return input;
}

void CFG::print(std::ostream &ost) const
{
    input->print(ost);
}