#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <vector>
#include "TranslatorFactory.h"
#include "cfg/BasicBlock.h"
#include "ast/AstNode.h"

class Translator {
public:
    Translator(AstNode* node_);
    virtual ~Translator();
    virtual BasicBlock* translate() = 0;

protected:
    TranslatorFactory& getFactory();

    AstNode* node;
};


#endif //TRANSLATOR_H
