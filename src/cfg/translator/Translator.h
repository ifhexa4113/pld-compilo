#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <vector>
#include "TranslatorFactory.h"
#include "cfg/CFG.h"
#include "cfg/BasicBlock.h"
#include "ast/AstNode.h"

class Translator {
public:
    Translator(AstNode* node_, CFG* cfg_);
    virtual ~Translator();

    /*
     * If the pointer returned by translate is nullptr,
     * then it means that the first BasicBlock can't be merged
     * with the last one.
     * Otherwise it can, and therefore it was not added
     * to the cfg.
     */
    virtual BasicBlock* translate() = 0;

protected:
    TranslatorFactory& getFactory();

    AstNode* node;
    CFG* cfg;
};


#endif //TRANSLATOR_H
