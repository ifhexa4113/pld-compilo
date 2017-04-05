#ifndef IF_TRANSLATOR_H
#define IF_TRANSLATOR_H

#include "cfg/translator/Translator.h"
#include "ast/block/conditional-structure/If.h"

class IfTranslator : public Translator
{
public:
    IfTranslator(If* f, CFG* cfg);
    ~IfTranslator();
    SubGraph* translate(Table* table = nullptr);
};

#endif //IF_TRANSLATOR_H