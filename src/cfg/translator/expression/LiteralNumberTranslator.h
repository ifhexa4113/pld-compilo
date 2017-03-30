
#ifndef PLD_COMPILO_LITERALNUMBERTRANSLATOR_H
#define PLD_COMPILO_LITERALNUMBERTRANSLATOR_H

#include "cfg/translator/Translator.h"
#include "ast/expression/LiteralNumberExpression.h"

class LiteralNumberTranslator : public Translator
{
public:
    LiteralNumberTranslator(LiteralNumberExpression* literalNumberExpression, CFG* cfg);
    ~LiteralNumberTranslator();
    SubGraph* translate();
};


#endif //PLD_COMPILO_LITERALNUMBERTRANSLATOR_H
