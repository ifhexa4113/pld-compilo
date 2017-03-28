#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <vector>
#include "TranslatorFactory.h"
#include "cfg/CFG.h"
#include "cfg/SubGraph.h"
#include "ast/AstNode.h"

class Translator {
public:
    Translator(AstNode* node_, CFG* cfg_);
    virtual ~Translator();
    virtual SubGraph* translate() = 0;

protected:
    TranslatorFactory& getFactory();

    AstNode* node;
    CFG* cfg;
};


#endif //TRANSLATOR_H
